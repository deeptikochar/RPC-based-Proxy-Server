#include <string>
#include <map>
#include <queue>
using namespace std;

struct data_element
{
  size_t size;
  size_t len;
  char *data;
};

class fifo_cache
{ 
	int MAX_SIZE;
	int size;
	std::map<string, data_element> dictionary;
	queue<string> fifo_queue;

	public:
	fifo_cache();
	fifo_cache(int max);

	int cache_fetch(string url, data_element *value);		// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, data_element value);		// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(int data_size);
	int cache_find(string url);                         	// Returns 1 if found, 0 if not
	int cache_remove(string url);							// Returns 1 if successful. 0 if not
	string cache_decideReplace();
};
