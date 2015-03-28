g++ -Wall -I/usr/local/include/thrift -c client.cpp -o client.o
g++ HTTPproxy.o client.o constants.o types.o -o client -L /usr/local/lib -lthrift
