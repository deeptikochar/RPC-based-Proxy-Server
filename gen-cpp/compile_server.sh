g++ -Wall -c ../curl_fetch.cpp -o curl_fetch.o
g++ -Wall -c ../random_cache.cpp -o random_cache.o
g++ -Wall -c ../lru_queue.cpp -o lru_queue.o
g++ -Wall -c ../lru_cache.cpp -o lru_cache.o
g++ -Wall -c ../fifo_cache.cpp -o fifo_cache.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy.cpp -o HTTPproxy.o
g++ -Wall -I/usr/local/include/thrift -DRANDOM -c server.cpp -o server_random.o
g++ -Wall -I/usr/local/include/thrift -DFIFO -c server.cpp -o server_fifo.o
g++ -Wall -I/usr/local/include/thrift -DLRU -c server.cpp -o server_lru.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_constants.cpp -o constants.o
g++ -Wall -I/usr/local/include/thrift -c HTTPproxy_types.cpp -o types.o
g++ HTTPproxy.o server_random.o constants.o types.o curl_fetch.o random_cache.o fifo_cache.o lru_queue.o lru_cache.o -o server_random -L /usr/local/lib -lthrift -lcurl
g++ HTTPproxy.o server_fifo.o constants.o types.o curl_fetch.o random_cache.o fifo_cache.o lru_queue.o lru_cache.o -o server_fifo -L /usr/local/lib -lthrift -lcurl
g++ HTTPproxy.o server_lru.o constants.o types.o curl_fetch.o random_cache.o fifo_cache.o lru_queue.o lru_cache.o -o server_lru -L /usr/local/lib -lthrift -lcurl

