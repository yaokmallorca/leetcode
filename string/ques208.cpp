#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Trie {
	class TreiNode {
		public:
			TreiNode* children[26];
			bool isWord;
			char word;

			TreiNode() {
				for(int i=0; i<26; ++i) children[i] = nullptr;
				isWord = false;
			}
	};

public:
	Trie() {
		root = new TreiNode();
	}
	
	void insert(string word) {
		TreiNode* node = root;
		for (auto c : word) {
			int ind = c - 'a';
			if (node->children[ind] == nullptr) 
				node->children[ind] = new TreiNode();
			node->children[ind]->word = c;
			node = node->children[ind];
		}
		node->isWord = true;
	}
	
	bool search(string word) {
		TreiNode* node = root;
		for (auto c : word) {
			int ind = c - 'a';
			if (node->children[ind] == nullptr) return false;
			node = node->children[ind];
		}
		return node->isWord;
	}
	
	bool startsWith(string prefix) {
		TreiNode* node = root;
		for (auto c : prefix) {
			int ind = c - 'a';
			if (node->children[ind] == nullptr) return false;
			node = node->children[ind];
		}
		return true;
	}

private:
	TreiNode* root;
};
