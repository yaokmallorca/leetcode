#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int maxProfit(std::vector<int>& nums) {
		int res = 0, buy = INT_MAX;
		for (auto num : nums) {
			buy = min(buy, num);
			res = max(res, num - buy);
		}
		return res;
	}

	int maxProfitII(std::vector<int>& prices) {
		int res = 0;
		for (int i = 0; i < prices.size()-1; ++i) {
			/* code */
			int tmp = prices[i+1] - prices[i];
			if (tmp > 0) {
				res += tmp;
			}
		}
		return res;
	}

	int maxProfitIIII(std::vector<int>& prices) {
		int n = prices.size(), k = 2;
		// std::vector< std::vector<int> > local(n, std::vector<int>(k+1, 0));
		// std::vector< std::vector<int> > global(n, std::vector<int>(k+1, 0));

		int global[n][3] = {0}, local[n][3] = {0};
		// local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff
		// global[i][j] = max(global[i-1][j], local[i][j])

		for (int i = 1; i < n; ++i) {
			/* code */
			int diff = prices[i] - prices[i-1];
			for (int j = 1; i <= k; ++j) {
				/* code */
				local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff;
				global[i][j] = max(global[i-1][j], local[i][j]);
			}
			// for (int j = 1; j <= 2; ++j) {
			//	 l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
			//	 g[i][j] = max(l[i][j], g[i - 1][j]);
			// }
		}


		return global[n-1][2];
	}

	int maxProfitIII(vector<int> &prices) {
		if (prices.empty()) return 0;
		int g[3] = {0};
		int l[3] = {0};
		for (int i = 0; i < prices.size() - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = 2; j >= 1; --j) {
				l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
				g[j] = max(l[j], g[j]);
			}
		}
		return g[2];
	}

	// question 309
	// cannot be in multi-trade
	// cannot buy in the next day of sell
	int maxProfitIV(std::vector<int>& prices) {
		if (prices.empty()) return 0;
		int prev = 0, profit = 0;

		for (int i = 1; i < prices.size(); ++i) {
			/* code */
			prev = max(profit, prices[i-1]-prices[i]);
			if (prev > profit) {
				++i;
				profit += prev;
			}
		}
		return profit;
	}

	template<typename T> 
	void showVec(std::vector<T> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}
	

	template<typename T> 
	void showVec(std::vector< std::vector<T> > nums) {
		for (auto num : nums) {
			showVec(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	// std::vector<int> nums = {3,3,5,0,0,3,1,4}; 
	// {7,6,4,3,1}; // {7,1,5,3,6,4}; {1,2,3,4,5};
	std::vector<int> prices = {1,2,3,0,2};
	Solution s;
	// cout << s.maxProfitIII(nums) << endl;

	cout << s.maxProfitIV(prices) << endl;


	return 0;
}