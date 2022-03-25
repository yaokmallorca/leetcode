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
		// cannot find key
		if (it == m.end()) return -1;
		l.splice(l.begin(), l, it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		// find key
		if (it != m.end()) l.erase(it->second);
		l.push_front(make_pair(key, value));
		m[key] = l.begin();
		if (l.size() > cap) {
			int k = l.rbegin()->first;
			l.pop_back();
			m.erase(k);
		}
	}

private:
	int cap;
	list< pair<int, int> > l;
	unordered_map<int, list< pair<int, int> >::iterator > m;


};