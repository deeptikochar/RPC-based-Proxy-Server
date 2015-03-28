g++ -Wall -c ../curl_fetch.cpp -o curl_fetch.o
g++ -Wall -c ../random_cache.cpp -o random_cache.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy.cpp -o HTTPproxy.o
g++ -Wall -I/usr/local/include/thrift -c server.cpp -o server.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_types.cpp -o types.o
g++ HTTPproxy.o server.o constants.o types.o curl_fetch.o random_cache.o -o server -L /usr/local/lib -lthrift -lcurl

