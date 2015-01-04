#include "rpc/MCRpcServer.h"
#include "rpc/inexor_service.pb.h"

#include "util/string_util.h"

#include <iostream>

#include <vector>

using namespace inexor::util;
using namespace inexor::net;
using namespace google::protobuf;

// TODO: Sending shit?
namespace inexor {
namespace rpc {

  uint MCRpcServer::ProcessAllCalls() {
    uint cnt=0;
    while (ProcessOneCall()) cnt++;
    return cnt;
  }
  

  bool MCRpcServer::ProcessOneCall() {
    MessageConnect *chan = NULL;

    // Process call request
    MC::bytes_on_channel res = mc->ReceiveChannel();
    MC::bytes call_bytes = res.first;
    if (call_bytes.empty()) {
      return false;
    }

    chan = res.second;

    ServiceCall cd;
    cd.ParseFromArray(&call_bytes[0], call_bytes.size());

    if (cd.type() == ServiceCall::RESPONSE) {
      // TODO: We should have a better way to handle that
      cerr << "[NOTE] Received bad RPC call: "
            << "Message was a response instead of a "
            << "request! This should not happen."
            << std::endl;
      return false;
    }
    // TODO: Moar error checking
    

    // Prepare all the data for doing the actual call
    string name = split_find_last(cd.function_name(), '.');
    std::cerr << "GOT CAL REQUEST: " << cd.function_name() << " -> " << name << std::endl;
    const MethodDescriptor *md =
      service->GetDescriptor()->FindMethodByName(name);

    Message *request =
      service->GetRequestPrototype(md).New();
    request->ParseFromString(cd.payload());

    Message *response =
      service->GetResponsePrototype(md).New();

    // Run the actual method
    // TODO: Implement an RpcController
    // TODO: Use the async callback
    service->CallMethod(md, NULL, request, response, NULL);

    // Prepare the response message
    ServiceCall rd;
    rd.set_function_name(cd.function_name());
    rd.set_call_uuid(cd.call_uuid());
    rd.set_type(ServiceCall::RESPONSE);
    rd.set_payload(response->SerializeAsString());

    std::vector<char> ret_bytes(rd.ByteSize());
    rd.SerializeToArray(&ret_bytes[0], ret_bytes.size());

    // And send the response message
    chan->Send(ret_bytes);

    // Clean up
    delete response;
    delete request;

    return true;
  }

}
}
