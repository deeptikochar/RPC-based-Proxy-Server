#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "random_cache.h"

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

int random_cache::cache_isFull(int data_size)
{
	if(size + data_size > MAX_SIZE)
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
	if(value.size > MAX_SIZE)
		return 0;
	while(cache_isFull(value.size))
	{
		cache_remove(cache_decideReplace());
	}
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
	// random_cache r(100);
	// const string url1 = "url1";
	// const string url2 = "url2";
	// const string url3 = "url3";
	// struct data_element elem1;
	// struct data_element elem2;
	// struct data_element elem3;
	// elem1.size = 10;
	// elem2.size = 30;
	// elem3.size = 50;
	// elem1.data = "data1";
	// elem2.data = "data2";
	// elem3.data = "data3";
	// elem1.len = 31;
	// elem2.len = 10;
	// elem3.len = 600;
	// struct data_element return_elem;
	// cout<<"Cache find (initial):"<<r.cache_find(url1)<<endl;
	// if(r.cache_insert(url1, elem1))
	// 	cout<<"Cache find (1):"<<r.cache_find(url1)<<endl;
	// cout<<"Cache find (2):"<<r.cache_find(url2)<<endl;
	// if(r.cache_fetch(url1, &return_elem))
	// 	cout<<"Success";
	// cout<<endl<<return_elem.size<<"\t"<<return_elem.len<<"\t"<<return_elem.data<<endl;
	// if(r.cache_insert(url2, elem2))
	// 	cout<<"Cache find (3):"<<r.cache_find(url2)<<endl;
	// if(r.cache_insert(url3, elem3))
	// {
	// 	cout<<"Inserted url3"<<endl;
	// 	cout<<"Is url1 present: "<<r.cache_find(url1)<<endl;
	// 	cout<<"Is url2 present: "<<r.cache_find(url2)<<endl;
	// 	cout<<"Is url3 present: "<<r.cache_find(url3)<<endl;

	// }
	// int remove_index = r.cache_decideReplace();
	// string remove_url = r.urls[remove_index];
	// r.cache_remove(remove_index);
	// cout<<"Remove index and url are"<<remove_index<<"\t"<<remove_url<<endl;
	// cout<<"Is it still present?"<<r.cache_find(remove_url)<<endl;

	return 0;
}