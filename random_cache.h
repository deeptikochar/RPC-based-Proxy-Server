#include <string>
#include <map>

using namespace std;

struct data_element
{
  size_t size;
  size_t len;
  char *data;
};

class random_cache
{ 
	// Later change to private for vars
	int num_entries;
	int MAX_SIZE;
	int size;
	std::map<string, data_element> dictionary;
	std::map<int, string> urls;

	public:
	random_cache();
	random_cache(int max);

	int cache_fetch(string url, data_element *value);		// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, data_element value);		// Returns 1 if successful, 0 if not

	private:
	int cache_isFull(int data_size);						// Returns 1 if full, 0 if not
	int cache_find(string url);                         	// Returns 1 if found, 0 if not	
	int cache_remove(int index);							// Returns 1 if successful. 0 if not
	int cache_decideReplace();								// Decides which cache entry to replace
};
