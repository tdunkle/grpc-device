#include <google/protobuf/util/time_util.h>
#include <grpcpp/impl/grpc_library.h>
#include <gtest/gtest.h>
#include <nifake_non_ivi/nifake_non_ivi_mock_library.h>
#include <nifake_non_ivi/nifake_non_ivi_service.h>
#include <server/session_resource_repository.h>

#include <iostream>
#include <numeric>
#include <string>

using namespace nifake_non_ivi_grpc;
using namespace ::testing;

namespace ni {
namespace tests {
namespace unit {

MATCHER(CustomU16Data, "")
{
  myUInt16 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT16_MAX && write_data_array[2] == 16;
}

MATCHER(CustomI16Data, "")
{
  myInt16 const* write_data_array = std::get<1>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT16_MAX && write_data_array[2] == INT16_MIN;
}

MATCHER(CustomI8Data, "")
{
  myInt8 const* write_data_array = std::get<2>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == INT8_MAX && write_data_array[2] == INT8_MIN;
}

MATCHER(CustomU8Data, "")
{
  myUInt8 const* write_data_array = std::get<0>(arg);
  return write_data_array[0] == 0 && write_data_array[1] == UINT8_MAX && write_data_array[2] == 16;
}

void SetU16Data(Unused, myUInt16* u16_data, Unused, Unused, Unused, Unused)
{
  u16_data[0] = 0;
  u16_data[1] = UINT16_MAX;
  u16_data[2] = 16;
};

void SetI16Data(Unused, Unused, Unused, myInt16* i16_data, Unused, Unused)
{
  i16_data[0] = 0;
  i16_data[1] = INT16_MAX;
  i16_data[2] = INT16_MIN;
};

void SetI8Data(Unused, Unused, Unused, Unused, Unused, myInt8* i8_data)
{
  i8_data[0] = 0;
  i8_data[1] = INT8_MAX;
  i8_data[2] = INT8_MIN;
};

void SetU8Data(Unused, myUInt8* u8_data)
{
  u8_data[0] = 0;
  u8_data[1] = UINT8_MAX;
  u8_data[2] = 16;
}

MATCHER_P(CVIAbsoluteTimeEq, lhs, "")
{
  return lhs.cviTime.msb == arg.cviTime.msb &&
      lhs.cviTime.lsb == arg.cviTime.lsb;
}

class NiFakeNonIviServiceTests : public ::testing::Test {
 protected:
  using FakeResourceRepository = nidevice_grpc::SessionResourceRepository<FakeHandle>;
  nidevice_grpc::SessionRepository session_repository_;
  std::shared_ptr<FakeResourceRepository> resource_repository_;
  NiFakeNonIviMockLibrary library_;
  NiFakeNonIviService service_;

  NiFakeNonIviServiceTests()
      : session_repository_(),
        resource_repository_(std::make_shared<FakeResourceRepository>(&session_repository_)),
        library_(),
        service_(&library_, resource_repository_)
  {
  }

  virtual ~NiFakeNonIviServiceTests() {}

  uint32_t init(const std::string& session_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, Init(StrEq(session_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitRequest request;
    request.set_session_name(session_name.c_str());
    InitResponse response;

    service_.Init(&context, &request, &response);

    return response.handle().id();
  }

  uint32_t init_with_handle_name_as_session_name(const std::string& handle_name, FakeHandle handle)
  {
    EXPECT_CALL(library_, InitWithHandleNameAsSessionName(StrEq(handle_name.c_str()), _))
        .WillOnce(DoAll(SetArgPointee<1>(handle), Return(kDriverSuccess)));

    ::grpc::ServerContext context;
    InitWithHandleNameAsSessionNameRequest request;
    request.set_handle_name(handle_name.c_str());
    InitWithHandleNameAsSessionNameResponse response;

    service_.InitWithHandleNameAsSessionName(&context, &request, &response);

    return response.handle().id();
  }

  int32 close_with_expected_handle(uint32_t session_id, FakeHandle expected_closed_handle)
  {
    EXPECT_CALL(library_, Close(expected_closed_handle))
        .WillOnce(Return(kDriverSuccess));
    ::grpc::ServerContext context;
    CloseRequest request;
    request.mutable_handle()->set_id(session_id);
    CloseResponse response;
    service_.Close(&context, &request, &response);

    return response.status();
  }

  void setup_iota_with_custom_size() {
    auto set_iota_data = [](int32 size_one, int32 size_two, int32* data) {
      auto out_size = (size_one == -1) ? size_two : size_one + 1;
      std::iota(data, data + out_size, 0);
    };

    EXPECT_CALL(library_, IotaWithCustomSize(_, _, _))
        .WillOnce(DoAll(
            Invoke(set_iota_data),
            Return(kDriverSuccess)));
  }

  static void EXPECT_IOTA_OF_SIZE(IotaWithCustomSizeResponse response, size_t size) {
    std::vector<int32> expected(size);
    std::iota(expected.begin(), expected.end(), 0);
    std::vector<int32> actual{response.data().cbegin(), response.data().cend()};
    EXPECT_THAT(actual, ContainerEq(expected));
  }
};

TEST_F(NiFakeNonIviServiceTests, InitSession_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 1234UL;
  auto session = init("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InitWithHandleNameAsSessionName_CloseSession_ClosesHandleAndSucceeds)
{
  const FakeHandle kHandle = 99999UL;
  auto session = init_with_handle_name_as_session_name("test", kHandle);
  EXPECT_NE(0, session);

  auto status = close_with_expected_handle(session, kHandle);

  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_U16DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomU16Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_u16_array(0);
  request.add_u16_array(UINT16_MAX);
  request.add_u16_array(16);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_U16DataOutOfRange_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_u16_array(UINT16_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(UINT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomI16Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(0);
  request.add_i16_array(INT16_MAX);
  request.add_i16_array(INT16_MIN);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);

  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(INT16_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);
  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I16DataOutOfRangeTooLow_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);

  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i16_array(INT16_MIN - 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);
  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT16_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataGetsCoerced)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .With(CustomI8Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(0);
  request.add_i8_array(INT8_MAX);
  request.add_i8_array(INT8_MIN);
  InputArraysWithNarrowIntegerTypesResponse response;

  service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataOutOfRangeTooHigh_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(INT8_MAX + 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MAX + 1)));
}

TEST_F(NiFakeNonIviServiceTests, InputArraysWithNarrowIntegerTypes_I8DataOutOfRangeTooLow_ReturnsError)
{
  EXPECT_CALL(library_, InputArraysWithNarrowIntegerTypes(_, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputArraysWithNarrowIntegerTypesRequest request;
  request.add_i8_array(INT8_MIN - 1);
  InputArraysWithNarrowIntegerTypesResponse response;

  auto status = service_.InputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::OUT_OF_RANGE, status.error_code());
  EXPECT_THAT(status.error_message(), HasSubstr(std::to_string(INT8_MIN - 1)));
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_U16)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_u16_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetU16Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.u16_data_size());
  EXPECT_EQ(0, response.u16_data().Get(0));
  EXPECT_EQ(UINT16_MAX, response.u16_data().Get(1));
  EXPECT_EQ(16, response.u16_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_I16)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_i16_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetI16Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.i16_data_size());
  EXPECT_EQ(0, response.i16_data().Get(0));
  EXPECT_EQ(INT16_MAX, response.i16_data().Get(1));
  EXPECT_EQ(INT16_MIN, response.i16_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArraysWithNarrowIntegerTypes_I8)
{
  ::grpc::ServerContext context;
  OutputArraysWithNarrowIntegerTypesRequest request;
  request.set_number_of_i8_samples(3);
  OutputArraysWithNarrowIntegerTypesResponse response;
  EXPECT_CALL(library_, OutputArraysWithNarrowIntegerTypes(_, _, _, _, _, _))
      .WillOnce(DoAll(
          Invoke(SetI8Data),
          Return(kDriverSuccess)));

  service_.OutputArraysWithNarrowIntegerTypes(&context, &request, &response);

  EXPECT_EQ(3, response.i8_data_size());
  EXPECT_EQ(0, response.i8_data().Get(0));
  EXPECT_EQ(INT8_MAX, response.i8_data().Get(1));
  EXPECT_EQ(INT8_MIN, response.i8_data().Get(2));
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, InputArrayOfBytes)
{
  EXPECT_CALL(library_, InputArrayOfBytes(_))
      .With(CustomU8Data())
      .Times(1);
  ::grpc::ServerContext context;
  InputArrayOfBytesRequest request;
  request.mutable_u8_array()->push_back(0);
  request.mutable_u8_array()->push_back(UINT8_MAX);
  request.mutable_u8_array()->push_back(16);
  InputArrayOfBytesResponse response;

  service_.InputArrayOfBytes(&context, &request, &response);

  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, OutputArrayOfBytes)
{
  EXPECT_CALL(library_, OutputArrayOfBytes(_, _))
      .WillOnce(DoAll(
          Invoke(SetU8Data),
          Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputArrayOfBytesRequest request;
  request.set_number_of_u8_samples(3);
  OutputArrayOfBytesResponse response;

  service_.OutputArrayOfBytes(&context, &request, &response);

  EXPECT_EQ(3, response.u8_data().size());
  EXPECT_EQ(0, (myUInt8)response.u8_data()[0]);
  EXPECT_EQ(UINT8_MAX, (myUInt8)response.u8_data()[1]);
  EXPECT_EQ(16, (myUInt8)response.u8_data()[2]);
  auto status = response.status();
  EXPECT_EQ(kDriverSuccess, status);
}

TEST_F(NiFakeNonIviServiceTests, IotaWithCustomSizeUsingFirstSizeOption_ReturnsIotaDataOfFirstSizePlusOne)
{
  const auto SIZE_ONE = 10;
  setup_iota_with_custom_size();
  ::grpc::ServerContext context;
  IotaWithCustomSizeRequest request;
  request.set_size_one(SIZE_ONE);
  request.set_size_two(100000);
  IotaWithCustomSizeResponse response;
  service_.IotaWithCustomSize(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_IOTA_OF_SIZE(response, SIZE_ONE + 1);
}

TEST_F(NiFakeNonIviServiceTests, IotaWithCustomSizeUsingSecondSizeOption_ReturnsIotaDataOfSecondSize)
{
  const auto SIZE_TWO = 20;
  setup_iota_with_custom_size();
  ::grpc::ServerContext context;
  IotaWithCustomSizeRequest request;
  request.set_size_one(-1);
  request.set_size_two(SIZE_TWO);
  IotaWithCustomSizeResponse response;

  service_.IotaWithCustomSize(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_IOTA_OF_SIZE(response, SIZE_TWO);
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_OneArgumentPair)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel"), BEAUTIFUL_COLOR_PINK, 1.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_mystring("channel");
  arg->set_myenum(BEAUTIFUL_COLOR_PINK);
  arg->set_powerupstate(1.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_TwoArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0, nullptr, BEAUTIFUL_COLOR_UNSPECIFIED, 0.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_mystring("channel0");
  arg->set_myenum(BEAUTIFUL_COLOR_PINK);
  arg->set_powerupstate(1.0);
  arg = request.add_string_and_enums();
  arg->set_mystring("channel1");
  arg->set_myenum(BEAUTIFUL_COLOR_AQUA);
  arg->set_powerupstate(2.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_FourArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(StrEq("inputName"), StrEq("channel0"), BEAUTIFUL_COLOR_PINK, 1.0, StrEq("channel1"), BEAUTIFUL_COLOR_AQUA, 2.0, StrEq("channel2"), BEAUTIFUL_COLOR_GREEN, 3.0, StrEq("channel3"), BEAUTIFUL_COLOR_BLACK, 4.0))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  auto arg = request.add_string_and_enums();
  arg->set_mystring("channel0");
  arg->set_myenum(BEAUTIFUL_COLOR_PINK);
  arg->set_powerupstate(1.0);
  arg = request.add_string_and_enums();
  arg->set_mystring("channel1");
  arg->set_myenum(BEAUTIFUL_COLOR_AQUA);
  arg->set_powerupstate(2.0);
  arg = request.add_string_and_enums();
  arg->set_mystring("channel2");
  arg->set_myenum(BEAUTIFUL_COLOR_GREEN);
  arg->set_powerupstate(3.0);
  arg = request.add_string_and_enums();
  arg->set_mystring("channel3");
  arg->set_myenum(BEAUTIFUL_COLOR_BLACK);
  arg->set_powerupstate(4.0);
  InputVarArgsResponse response;

  service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_NoArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  InputVarArgsResponse response;

  auto status = service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

TEST_F(NiFakeNonIviServiceTests, InputVarArgs_FiveArgumentPairs)
{
  EXPECT_CALL(library_, InputVarArgs(_, _, _, _, _, _, _, _, _, _, _, _, _))
      .Times(0);
  ::grpc::ServerContext context;
  InputVarArgsRequest request;
  request.set_input_name("inputName");
  for (auto i = 0; i < 5; i++) {
    request.add_string_and_enums();
  }
  InputVarArgsResponse response;

  auto status = service_.InputVarArgs(&context, &request, &response);

  EXPECT_EQ(grpc::StatusCode::INVALID_ARGUMENT, status.error_code());
}

const int64 SecondsFromCVI1904EpochTo1970Epoch = 2082844800LL;
TEST_F(NiFakeNonIviServiceTests, InputTimestamp_UnixEpoch)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0;
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::Timestamp* timestamp_pb = request.mutable_when();
  timestamp_pb->set_seconds(0);
  timestamp_pb->set_nanos(0);
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, InputTimestamp_UnixEpochWithFractionalSeconds)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0x8000000000000000LL;
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(timestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::Timestamp* timestamp_pb = request.mutable_when();
  timestamp_pb->set_seconds(0);
  // exactly .5 seconds
  timestamp_pb->set_nanos(500 * 1000 * 1000);
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

// Determined from CVI:
// CVIAbsoluteTime msb: 3709898694
// UTC time string: "2021-07-23T15:24:54.00Z
CVIAbsoluteTime cviKnownTimestamp = {0, 3709898694LL};
const std::string cviKnownTimestampString = "2021-07-23T15:24:54.00Z";

TEST_F(NiFakeNonIviServiceTests, InputTimestamp_KnownValue)
{
  EXPECT_CALL(library_, InputTimestamp(CVIAbsoluteTimeEq(cviKnownTimestamp)))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  InputTimestampRequest request;
  google::protobuf::util::TimeUtil::FromString(cviKnownTimestampString, request.mutable_when());
  InputTimestampResponse response;

  service_.InputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_UnixEpoch)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0;
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(timestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(0, response.when().seconds());
  EXPECT_EQ(0, response.when().nanos());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_UnixEpochWithFractionalSeconds)
{
  CVIAbsoluteTime timestamp;
  timestamp.cviTime.msb = SecondsFromCVI1904EpochTo1970Epoch;
  timestamp.cviTime.lsb = 0x8000000000000000LL;
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(timestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(0, response.when().seconds());
  EXPECT_EQ(500 * 1000 * 1000, response.when().nanos());
}

TEST_F(NiFakeNonIviServiceTests, OutputTimestamp_KnownValue)
{
  EXPECT_CALL(library_, OutputTimestamp(_))
      .WillOnce(DoAll(SetArgPointee<0>(cviKnownTimestamp), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  OutputTimestampRequest request;
  OutputTimestampResponse response;

  service_.OutputTimestamp(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  google::protobuf::Timestamp timestamp;
  google::protobuf::util::TimeUtil::FromString(cviKnownTimestampString, &timestamp);
  EXPECT_EQ(timestamp, response.when());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeDouble_Succeeds)
{
  const auto ATTRIBUTE = MarbleAttributes::MARBLE_ATTRIBUTE_WEIGHT;
  const auto VALUE = 1.2345;
  EXPECT_CALL(library_, SetMarbleAttributeDouble(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeDoubleRequest request;
  request.set_attribute(ATTRIBUTE);
  request.set_value(VALUE);
  SetMarbleAttributeDoubleResponse response;
  service_.SetMarbleAttributeDouble(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeInt32_Succeeds)
{
  const auto ATTRIBUTE = MarbleAttributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_GREEN;
  EXPECT_CALL(library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  request.set_value(VALUE);
  SetMarbleAttributeInt32Response response;
  service_.SetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, SetMarbleAttributeInt32Raw_Succeeds)
{
  const auto ATTRIBUTE = MarbleAttributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = 9999;
  EXPECT_CALL(library_, SetMarbleAttributeInt32(_, ATTRIBUTE, VALUE))
      .WillOnce(Return(kDriverSuccess));
  ::grpc::ServerContext context;
  SetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  request.set_value_raw(VALUE);
  SetMarbleAttributeInt32Response response;
  service_.SetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
}

TEST_F(NiFakeNonIviServiceTests, GetMarbleAttributeInt32_Succeeds)
{
  const auto ATTRIBUTE = MarbleAttributes::MARBLE_ATTRIBUTE_COLOR;
  const auto VALUE = MarbleInt32AttributeValues::MARBLE_INT32_BEAUTIFUL_COLOR_AQUA;
  EXPECT_CALL(library_, GetMarbleAttributeInt32(_, ATTRIBUTE, _))
      .WillOnce(DoAll(SetArgPointee<2>(VALUE), Return(kDriverSuccess)));
  ::grpc::ServerContext context;
  GetMarbleAttributeInt32Request request;
  request.set_attribute(ATTRIBUTE);
  GetMarbleAttributeInt32Response response;
  service_.GetMarbleAttributeInt32(&context, &request, &response);

  EXPECT_EQ(kDriverSuccess, response.status());
  EXPECT_EQ(VALUE, response.value());
}
}  // namespace unit
}  // namespace tests
}  // namespace ni