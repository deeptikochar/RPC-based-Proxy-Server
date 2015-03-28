// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "HTTPproxy.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <stdio.h>
#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace  ::proxyspace;

int main(int argc, char **argv) {
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  response serverResponse;
  HTTPproxyClient client(protocol);
  try {
	  
	  transport->open();
	  client.request(serverResponse, "http://www.yahoo.com");
    std::cout<<"The returned response document is:\n"<<serverResponse.document;
    std::cout<<"\nThe response code is: "<<serverResponse.response_code<<"\n";
    client.shutdown();
	  transport->close();
  } catch (TException& tx) {
  std::cout << "ERROR: " << tx.what() <<std::endl;
  }
  // Check TException import and use !
  return 0;
}
