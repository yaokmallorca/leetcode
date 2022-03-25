#include <stdlib.h>
#include <iostream>
#include <stack> 
#include <unordered_map>
#include <list>
#include <utility>

class LRUCache
{
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end()) return -1;
		l.splice(l.begin(), l, it->second);
		return splice->second->second;
	}

	void put(int key, int value) {


	}

private:
	int cap;
	list< pair<int, int> > l;
	unordered_map<int, list< pair<int, int> >::iterator> m;
};
