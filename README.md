INSTRUCTIONS

Prerequisites
* Compiling will require thrift and libcurl to be installed.
* The Makefile assumes standard location of packages.

Compilation
Run "make" in the top directory

To remove all object files and executables, run "make clean".

Execution

To run the server, use one of the following commands:
./server_random [cache_size]
./server_fifo [cache_size]
./server_lru [cache_size]

To run the client, use the following command:
./client <num_loops> <access_pattern_type>

<access_pattern_type> = 1 for random
						2 for repetitive

To run the experiments:

Server:
chmod 777 server_test.sh
./server_test.sh

Client
chmod 777 run_client.sh
./run_client.sh

