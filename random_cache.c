#include <stdlib.h>
#include <time.h>
#include <iostream>
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
	public:
	int num_entries;
	int MAX_SIZE;
	int size;
	std::map<string, data_element> dictionary;
	std::map<int, string> urls;

	//public:
	random_cache();
	random_cache(int max);

	int cache_isFull(data_element value);
	int cache_find(string url);                         	// Returns 1 if found, 0 if not
	int cache_fetch(string url, data_element *value);		// Returns 1 if found and sets value accordingly, 0 if not present.
	int cache_insert(string url, data_element value);		// Returns 1 if successful, 0 if not
	int cache_remove(int index);							// Returns 1 if successful. 0 if not
	int cache_decideReplace();
};

random_cache::random_cache()
{
	MAX_SIZE = 1024;
	num_entries = 0;
	size = 0;
	srand(time(NULL));
}

random_cache::random_cache(int max)
{
	MAX_SIZE = max;
	num_entries = 0;
	size = 0;
	srand(time(NULL));
}

int random_cache::cache_isFull(data_element value)
{
	if(size + value.size > MAX_SIZE)
		return 1;

	return 0;
}

int random_cache::cache_find(string url)
{
	//Check if url is a key in the map
	if(dictionary.count(url) == 0)
		return 0;
	return 1;
}

int random_cache::cache_fetch(string url, data_element *value)
{
	if(cache_find(url))
	{
		data_element val = dictionary.find(url)->second;
		value->size = val.size;
		value->len = val.len;
		value->data = val.data;
		return 1;
	}
	return 0;
}

int random_cache::cache_insert(string url, data_element value)
{
	if(cache_isFull(value))
		return 0;	
	
	dictionary[url] = value;
	size = size + value.size;
	urls[num_entries] = url;
	num_entries++;
	return 1;
}

int random_cache::cache_remove(int index)
{
	string url = urls[index];
	data_element temp;
	if(cache_fetch(url, &temp) == 0)
		return 0;
	size = size - temp.size;
	
	dictionary.erase(url);
	urls[index] = urls[num_entries-1];
	urls.erase(num_entries-1);
	num_entries--;
	return 1;
}

int random_cache::cache_decideReplace()
{
	int index = rand() % num_entries;
	return index;
}

int main(int argc, char const *argv[])
{
	random_cache r;
	const string url1 = "blah";
	const string url2 = "moreblah";
	struct data_element elem1;
	struct data_element elem2;
	elem1.size = 10;
	elem2.size = 30;
	elem1.data = "hhh";
	elem2.data = "jhhjkbfjf";
	elem1.len = 1;
	elem2.len = 5;
	struct data_element return_elem;
	cout<<"Cache find (initial):"<<r.cache_find(url1)<<endl;
	if(r.cache_insert(url1, elem1))
		cout<<"Cache find (1):"<<r.cache_find(url1)<<endl;
	cout<<"Cache find (2):"<<r.cache_find(url2)<<endl;
	if(r.cache_fetch(url1, &return_elem))
		cout<<"Success";
	cout<<endl<<return_elem.size<<"\t"<<return_elem.len<<"\t"<<return_elem.data<<endl;
	if(r.cache_insert(url2, elem2))
		cout<<"Cache find (3):"<<r.cache_find(url2)<<endl;
	int remove_index = r.cache_decideReplace();
	string remove_url = r.urls[remove_index];
	
	// std::map<int, string> m;
	// m[0] = "Hi";
	// m[1] = "Hi1";
	// m[2] = "Hi2";
	// m[0] = m[2];
	// cout<<"new m[0] is "<<m[0]<<endl;
	// m.erase(2);
	// cout<<"find 2 "<<m.count(2);
	r.cache_remove(remove_index);
	cout<<"Remove index and url are"<<remove_index<<"\t"<<remove_url<<endl;
	cout<<"Is it still present?"<<r.cache_find(remove_url)<<endl;

	return 0;
}