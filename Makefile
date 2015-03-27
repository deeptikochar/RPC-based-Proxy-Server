
all: random_cache.o fifo_cache.o lru_queue.o lru_cache.o
	g++ -w -c random_cache.cpp
	g++ -w -c fifo_cache.cpp
	g++ -w -c lru_queue.cpp
	g++ -w -c lru_cache.cpp
#	g++ -w -o lru_cache lru_cache.o lru_queue.o

clean:
	rm -rf *.o
