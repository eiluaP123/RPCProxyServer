#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <assert.h>

using namespace std;

map<string, string> cache_map;
size_t curr_cache_size = 0;

void add_page(string url, string data, size_t len_data, size_t cache_size){
	map<string, string>::iterator itr;
//	printf("number of elements in map %d\n",cache_map.size());

	//1.There is space in the cache
	size_t curr_empty = cache_size - curr_cache_size;
//	printf("current empty %d, cache size %d, current cache size %d\n",curr_empty, cache_size, curr_cache_size);
	printf("url %s with len_data %d\n",url.c_str(),len_data);
	assert(!(len_data > cache_size));
	if (len_data < curr_empty){
		curr_cache_size += len_data;
		cache_map.insert (pair<string,string>(url,data));
//		printf("number of elements in map %d\n",cache_map.size());
	}
	else {
		while(len_data > curr_empty) {
			int random = rand() % cache_map.size();
			for(itr=cache_map.begin(); itr!=cache_map.end();++itr){
//				printf("random %d\n",random);
				if(random==0)
					break;
				else random--;
			}
//			printf("\ncoming out of add in cache.cpp\n");
			assert(itr!=cache_map.end());
//				printf("url to be deleted %s\n",itr->first.c_str());
				string arr = itr->second;
//				printf("size deleted %d and len of data to be added %d\n", arr.size(), len_data);
				size_t free = arr.size();
				cache_map.erase(itr);
//				printf("number of elements in map %d\n",cache_map.size());
				curr_cache_size	= curr_cache_size - free;
				curr_empty = curr_empty + free;
//				printf("current empty %d, cache size %d, current cache size %d\n",curr_empty, cache_size, curr_cache_size);
				itr = cache_map.begin();

		}
		cache_map.insert (pair<string,string>(url,data));	
//		printf("number of elements in map %d\n",cache_map.size());
		curr_cache_size += len_data;	
	}
}

string search_page(string url){
	map<string, string>::iterator itr;
	itr = cache_map.begin();
	itr = cache_map.find(url);
	if(itr != cache_map.end())
		return cache_map[url];
	else
		return "NOT_FOUND";
}	
