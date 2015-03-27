
#include <iostream>
#include "fifo_cache.h"

fifo_cache::fifo_cache()
{
	MAX_SIZE = 1024;
	size = 0;
}

fifo_cache::fifo_cache(int max)
{
	MAX_SIZE = max;
	size = 0;
}

int fifo_cache::cache_isFull(data_element value)
{
	if(size + value.size > MAX_SIZE)
		return 1;

	return 0;
}

int fifo_cache::cache_find(string url)
{
	//Check if url is a key in the map
	if(dictionary.count(url) == 0)
		return 0;
	return 1;
}

int fifo_cache::cache_fetch(string url, data_element *value)
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

int fifo_cache::cache_insert(string url, data_element value)
{
	if(cache_isFull(value))
		return 0;	
	
	dictionary[url] = value;
	size = size + value.size;
	fifo_queue.push(url);
	return 1;
}

int fifo_cache::cache_remove(string url)
{
	data_element temp;
	if(cache_fetch(url, &temp) == 0)
		return 0;
	size = size - temp.size;
	dictionary.erase(url);
	int i;
	fifo_queue.pop();
	return 1;
}

string fifo_cache::cache_decideReplace()
{
	return fifo_queue.front();
}

int main(int argc, char const *argv[])
{
	fifo_cache r;
	string url1 = "blah";
	string url2 = "moreblah";
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
	string remove_url = r.cache_decideReplace();
	cout<<remove_url<<endl;
	r.cache_remove(remove_url);
	cout<<"Removed url is present? "<<r.cache_find(remove_url)<<endl;

	return 0;
}