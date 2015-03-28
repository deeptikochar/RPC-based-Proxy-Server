g++ -Wall -I/usr/local/include/thrift -c HTTPproxy.cpp -o HTTPproxy.o
g++ -Wall -I/usr/local/include/thrift -c server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_types.cpp -o types.o
g++ HTTPproxy.o server.o constants.o types.o -o server -L /usr/local/lib -lthrift

