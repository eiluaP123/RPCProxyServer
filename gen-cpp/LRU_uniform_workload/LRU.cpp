#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <assert.h>
#include <list>

using namespace std;

map<string, string> cache_map;
size_t curr_cache_size = 0;
list<string> l;

void add_page(string url, string data, size_t len_data, size_t cache_size){
	map<string, string>::iterator itr;
//	printf("number of elements in map %d\n",cache_map.size());

	//1.There is space in the cache
	size_t curr_empty = cache_size - curr_cache_size;
//	printf("current empty %d, cache size %d, current cache size %d\n",curr_empty, cache_size, curr_cache_size);
//	printf("url %s with len_data %d\n",url.c_str(),len_data);
	assert(!(len_data > cache_size));
	if (len_data < curr_empty){
		curr_cache_size += len_data;
		cache_map.insert (pair<string,string>(url,data));
//		printf("this url is %s and front of the queue right now is %s\n",url.c_str(),l.front().c_str());
		l.push_front(url);
//		printf("this url is %s and front of the queue after push back is %s\n",url.c_str(),l.front().c_str());
//		printf("number of elements in map %d\n",cache_map.size());
	}
	else {
		while(len_data > curr_empty) {
			//delete the first page
			string get_url = l.back();
			//itr = cache_map.begin();
			itr = cache_map.find(get_url);
//			printf("url to be deleted %s\n",itr->first.c_str());
			string arr = itr->second;
//			printf("size deleted %d and len of data to be added %d\n", arr.size(), len_data);
			size_t free = arr.size();
			cache_map.erase(itr);
//			printf("this url is %s and end of the queue right now is %s\n",url.c_str(),l.back().c_str());
			l.pop_back();
//			printf("this url is %s and end of the queue now is %s\n",url.c_str(),l.back().c_str());
//			printf("number of elements in map %d\n",cache_map.size());
			curr_cache_size	= curr_cache_size - free;
			curr_empty = curr_empty + free;
//			printf("current empty %d, cache size %d, current cache size %d\n",curr_empty, cache_size, curr_cache_size);
		}
		cache_map.insert (pair<string,string>(url,data));	
//		printf("this url is %s and front of the queue right now is %s\n",url.c_str(),l.front().c_str());
		l.push_front(url);
//		printf("this url is %s and front of the queue after push back is %s\n",url.c_str(),l.front().c_str());
		printf("number of elements in map %d\n",cache_map.size());
		curr_cache_size += len_data;	
	}
}

string search_page(string url){
	map<string, string>::iterator itr;
	itr = cache_map.begin();
	itr = cache_map.find(url);
	if(itr != cache_map.end()){
		string return_value = cache_map[url];
		assert(!l.empty());
		l.remove(url);
		l.push_front(url);
		return return_value;
	}		
	else
		return "NOT_FOUND";
}
