#include <iostream>
#include <string>
#include <cstring> // strcmp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};

	void ShowVec(std::vector<string> strs) {
		for (auto str : strs) {
			cout << str.c_str() << endl;
		}
		cout << endl;
	}

	void ShowVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void ShowVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			ShowVec(num);
		}
		// cout << endl;
	}

	void ShowPair(std::vector< pair<int, int> > pairs) {
		std::vector< pair<int, int> >::iterator it = pairs.begin();
		for(;it!=pairs.end(); ++it) {
			cout << "(" << it->first << ", " << it->second << "), ";
		}
		cout << endl;
	}

	void ShowPair(std::vector< std::vector< pair<int, int> > > grids) {
		for (auto grid : grids) {
			ShowPair(grid);
		}
	}

	
public:
	// back tracking
	std::vector<string> exist(std::vector< std::vector<char> >& letters, string word) {
		string out = "";
		int rows = letters.size(), cols = letters[0].size();
		// has duplicated
		std::vector<string> res;
		exist_helper_dfs(letters, 0, 0, out, word, res);
		// return std::vector<string>(res.begin(), res.end());
		return res;

		// no duplicated
		// std::vector<string> res;
		// std::vector< std::vector<bool> > visited(letters.size(), std::vector<bool>(letters[0].size(), false));
		// exist_helper_nodup(letters, 0, 0, out, word, res, visited);
		// return res;
	}

	// DFS
	void exist_helper_dfs(std::vector< std::vector<char> > letters, int r, int c, 
		string out, string word, std::vector<string>& res) {
		int rows = letters.size(), cols = letters[0].size();
		if (out.size() == word.size()) {
			res.push_back(out);
			return;
		}
		if (r<=rows-1 && c<=cols-1) {
			out += letters[r][c];
			exist_helper_dfs(letters, r+1, c, out, word, res);
			exist_helper_dfs(letters, r, c+1, out, word, res);
		} 
	}

	// dp algorithm
	std::vector<string> exist_dp(std::vector< std::vector<char> >& letters) {
		std::vector<string> res;
		std::vector<char> out;
		std::vector< std::vector<int> > dp(letters.size(), std::vector<int>(letters[0].size(), 0));
		int rows = dp.size(), cols = dp[0].size();
		for(int i=0; i<dp.size(); ++i) dp[i][0] = 1;
		for(int i=0; i<dp[0].size(); ++i) dp[0][i] = 1;

		for (int i=1; i<dp.size(); ++i) {
			for (int j=1; j<dp[0].size(); ++j) {
				// out.push_back(letters[i][j]);
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				// if (out.size() >= 5) {
				// 	string out(out.begin(), out.end());
				// 	cout << "out: " << out.c_str() << endl;
				// 	res.push_back(out);
				// 	out.clear();
				// }
			}
		}
		cout << "dp array: " << endl;
		ShowVec(dp);
		return res;
	}

	std::vector< std::vector< pair<int, int> > > uniquePathsIII(std::vector< std::vector<int> >& grids) {
		int m = grids.size(), n = grids[0].size();
		int x0 = 0, y0 = 0, target = 1;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (grids[i][j] == 1) {
					x0 = i; y0 = j;
				} else if (grids[i][j] == 0) {
					++ target;
				}
			}
		}
		std::vector< std::vector< pair<int, int> > > res;
		std::vector< pair<int, int> > out;
		cout << "target: " << target << endl;
		helper(grids, target, x0, y0, out, res);
		return res;
	}

	void helper(std::vector< std::vector<int> >& grid, int& target, 
		int i, int j, std::vector< pair<int, int> >& out,
		std::vector< std::vector< pair<int, int> > >& res) {
		int m = grid.size(), n = grid[0].size();
		if (i<0 || i>=m || j<0 || j>=n || grid[i][j]<0) return;
		if (grid[i][j] == 2) {
			if (target == 0) {
				out.push_back(make_pair(i, j));
				res.push_back(out);
			}
			return;
		}
		out.push_back(make_pair(i, j));
		grid[i][j] = -2;
		--target;
		helper(grid, target, i, j+1, out, res);
		helper(grid, target, i, j-1, out, res);
		helper(grid, target, i+1, j, out, res);
		helper(grid, target, i-1, j, out, res);
		out.pop_back();
		grid[i][j] = 0;
		++target;
	}

	std::vector<string> findWords(std::vector< std::vector<char> >& letters, std::vector<string> words) {
		std::set<string> res;
		int m = letters.size(), n = letters[0].size();
		string out = "";
		std::vector< pair<int, int> > start_pts;
		for (string word : words) {
			char starter = word.c_str()[0];
			for (int i=0; i<m; ++i) {
				for (int j=0; j<n; ++j) {
					if (letters[i][j] == starter) {
						start_pts.push_back(make_pair(i, j));
					}
				}
			}
		}
		// ShowPair(start_pts);
		for (int i=0; i<start_pts.size(); ++i) {
			pair<int, int> pt = start_pts[i];
			find_helper(letters, pt.first, pt.second, words[i], out, res);
		}
		return std::vector<string>(res.begin(), res.end());
	}


	void find_helper(std::vector< std::vector<char> >& letters, int i, int j, 
		string word, string& out, std::set<string>& res) {
		int m = letters.size(), n = letters[0].size();
		if (i<0 || i>=m || j<0 || j>=n || letters[i][j] == '#') return;
		// if out is not word, return
		if (string::npos == word.find(out))
			return;
		if (0 == strcmp(out.c_str(), word.c_str())) {
			res.insert(out);
			return;
		}

		char tmp = letters[i][j];
		letters[i][j] = '#';
		out += tmp;
		find_helper(letters, i, j+1, word, out, res);
		find_helper(letters, i, j-1, word, out, res);
		find_helper(letters, i+1, j, word, out, res);
		find_helper(letters, i-1, j, word, out, res);
		letters[i][j] = tmp;
		out = out.substr(0, out.size()-1);
	}

	/*
	// answer for question 212
    struct TrieNode {
        TrieNode *child[26];
        string str;
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visit, vector<string>& res) { 
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }

	*/


};

int main() {
	Solution s;

	cout << "<<<<<<<<<<<<<<<<< question 79 <<<<<<<<<<<<<<<<<" << endl;
	std::vector< std::vector<char> > letters = {{'A','B','C','D'}, 
												{'E','F','G','H'},
												{'I','J','K','M'}};\
	std::vector<string> res = s.exist_dp(letters);
	s.ShowVec(res);

	cout << "<<<<<<<<<<<<<<<<< question 900 <<<<<<<<<<<<<<<<<" << endl;
	std::vector< std::vector<int> > grids = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
	s.ShowVec(grids);
	std::vector< std::vector< pair<int, int> > > grid_res = s.uniquePathsIII(grids);
	s.ShowPair(grid_res);

	cout << "<<<<<<<<<<<<<<<<< question 212 <<<<<<<<<<<<<<<<<" << endl;
	std::vector< std::vector<char> > letters_212 = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	std::vector<string> words = {"oath","pea","eat","rain"};
	std::vector<string> ques212_results; // eat oath
	ques212_results = s.findWords(letters_212, words);
	s.ShowVec(ques212_results);

	return 0;
}