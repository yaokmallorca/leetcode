#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int bestSellStockII(std::vector<int> prices) {
	int n = prices.size();
	int max_prices = 0;
	for(int i=1; i<n; i++) {
		if (prices[i] > prices[i-1]) {
			max_prices += prices[i] - prices[i-1];
		}
	}
	return max_prices;
}

int maxProfile(int k, std::vector<int> prices) {
	int dp_l[k+1] = {0};
	int dp_g[k+1] = {0};

	for (int i=1; i<prices.size(); i++) {
		int diff = prices[i] - prices[i-1];
		for (int j=1; j<k; j++) {
			dp_l = max(dp_g[j-1]+max(0, diff), dp_l[j]+diff);
			dp_g = max(dp_l[j], dp_g[j]);
		}
	}
	return dp_g[k];
}




int main() {
	std::vector<int> prices = {3,2,6,5,0,3};
	int max_prices = maxProfile(prices);
	cout << "best sell stock: " << max_prices << endl;
}
