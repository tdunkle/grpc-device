//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-FAKE-NON-IVI
//---------------------------------------------------------------------
#ifndef NIFAKE_NON_IVI_GRPC_MOCK_LIBRARY_H
#define NIFAKE_NON_IVI_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nifake_non_ivi_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiFakeNonIviMockLibrary : public nifake_non_ivi_grpc::NiFakeNonIviLibraryInterface {
 public:
  MOCK_METHOD(int32, Close, (FakeHandle handle), (override));
  MOCK_METHOD(int32, GetMarbleAttributeDouble, (FakeHandle handle, int32 attribute, double* value), (override));
  MOCK_METHOD(int32, GetMarbleAttributeInt32, (FakeHandle handle, int32 attribute, int32* value), (override));
  MOCK_METHOD(int32, Init, (const char sessionName[], FakeHandle* handle), (override));
  MOCK_METHOD(int32, InitWithHandleNameAsSessionName, (const char handleName[], FakeHandle* handle), (override));
  MOCK_METHOD(int32, InputArraysWithNarrowIntegerTypes, (const myUInt16 u16Array[], const myInt16 i16Array[], const myInt8 i8Array[]), (override));
  MOCK_METHOD(int32, IotaWithCustomSize, (int32 sizeOne, int32 sizeTwo, int32 data[]), (override));
  MOCK_METHOD(int32, OutputArraysWithNarrowIntegerTypes, (int32 numberOfU16Samples, myUInt16 u16Data[], int32 numberOfI16Samples, myInt16 i16Data[], int32 numberOfI8Samples, myInt8 i8Data[]), (override));
  MOCK_METHOD(int32, InputArrayOfBytes, (const myUInt8 u8Array[]), (override));
  MOCK_METHOD(int32, OutputArrayOfBytes, (int32 numberOfU8Samples, myUInt8 u8Data[]), (override));
  MOCK_METHOD(int32, RegisterCallback, (myInt16 inputData, CallbackPtr callbackFunction, void* callbackData), (override));
  MOCK_METHOD(int32, ReadStream, (int32 start, int32 stop, int32* value), (override));
  MOCK_METHOD(int32, InputTimestamp, (CVIAbsoluteTime when), (override));
  MOCK_METHOD(int32, OutputTimestamp, (CVIAbsoluteTime* when), (override));
  MOCK_METHOD(int32, InputVarArgs, (const char inputName[], const char channelName[], int32 color, double powerUpState, const char myString0[], int32 myEnum0, double powerUpState0, const char myString1[], int32 myEnum1, double powerUpState1, const char myString2[], int32 myEnum2, double powerUpState2), (override));
  MOCK_METHOD(int32, SetMarbleAttributeDouble, (FakeHandle handle, int32 attribute, double value), (override));
  MOCK_METHOD(int32, SetMarbleAttributeInt32, (FakeHandle handle, int32 attribute, int32 value), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIFAKE_NON_IVI_GRPC_MOCK_LIBRARY_H