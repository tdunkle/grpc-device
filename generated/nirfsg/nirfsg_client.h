
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-RFSG.
//---------------------------------------------------------------------
#ifndef NIRFSG_GRPC_CLIENT_H
#define NIRFSG_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nirfsg.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nirfsg_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiRFSG::Stub>;
using namespace nidevice_grpc::experimental::client;


InitResponse init(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetErrorResponse get_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
InitWithOptionsResponse init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const pb::string& option_string);

} // namespace nirfsg_grpc::experimental::client

#endif /* NIRFSG_GRPC_CLIENT_H */