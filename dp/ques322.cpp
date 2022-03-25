#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
	int coinChange(std::vector<int>& coins, int amount) {
		unordered_map<int, int> memo;// (amount+1, INT_MAX);
		memo[0] = 0;
		// std::vector<int> cur;
		std::vector< std::vector<int> > res;
		// int min_val = coinChangeDFS(coins, amount, memo);
		coinChangeDFS(coins, amount, memo, res);
		cout << res.size() << endl;
		showVec(res);
		return 0;
	}

	int coinChangeDFS(std::vector<int>& coins, int amount, unordered_map<int, int>& memo) {
		if (amount < 0) return -1;
		if (memo.count(amount)) return memo[amount];
		int cur = INT_MAX;
		std::vector<int> cur_coins;
		for (int i = 0; i < coins.size(); ++i) {
			/* code */
			cur_coins.push_back(coins[i]);
			int tmp = coinChangeDFS(coins, amount-coins[i], memo);
			if (tmp >= 0) {
				cur = min(cur, tmp + 1);
			}

		}
		// return memo[amount] = (cur == INT_MAX) ? -1 : cur;
		memo[amount] = (cur == INT_MAX) ? -1 : cur;
		return memo[amount];
		// return cur == INT_MAX ? -1 : cur;
	}

	void coinChangeDFS(std::vector<int>& coins, int amount, unordered_map<int, int>& memo,
		std::vector< std::vector<int> >& res) {
		if (amount < 0) return;
		if (memo.count(amount)) return;
		std::vector<int> cur;
		for (int i = 0; i < coins.size(); ++i) {
			/* code */
			cur.push_back(coins[i]);
			cout << amount - coins[i] << endl;
			if (amount-coins[i] == 0) {
				res.push_back(cur);
			}
			coinChangeDFS(coins, amount-coins[i], memo, res);
		}
		return;

	} 
	
	void showVec(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVec(std::vector< std::vector<int> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> coins = {1, 2, 5};
	Solution s;
	cout << s.coinChange(coins, 11) << endl;
	return 0;
}