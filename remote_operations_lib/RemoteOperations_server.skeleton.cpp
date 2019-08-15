// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "RemoteOperations.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::RemoteOperations::thrift::impl;

class RemoteOperationsHandler : virtual public RemoteOperationsIf {
 public:
  RemoteOperationsHandler() {
    // Your initialization goes here
  }

  void connect(std::string& _return) {
    // Your implementation goes here
    printf("connect\n");
  }

  bool insertUser(const UserData& userData) {
    // Your implementation goes here
    printf("insertUser\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<RemoteOperationsHandler> handler(new RemoteOperationsHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new RemoteOperationsProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

