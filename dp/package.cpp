#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	/*
	dp[i][j]: it is the maximal weight when the ith product is put into 
			  the package (the maximal weight is j)
	dp[i][j] = max( dp[i-1][j]							// the ith product cannot put into the package
			        dp[i-1][j-weight[i]] + value[i])	// the ith product is put into the package
	*/
	int maxValueI(std::vector<int>& values, std::vector<int>& weights, 
		int package_weight) {
		int m = weights.size();
		std::vector< std::vector<int> > dp(m+1, std::vector<int>(package_weight+1, 0));
		for (int i=weights[0]; i<=package_weight; ++i) dp[0][i] = values[0];

		for (int i=1; i <= m; ++i) {
			/* code */
			for (int j=0; j <= package_weight; ++j ) {
				if (j < weights[i]) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
			}
		}
		showVec(dp);
		return dp[m][package_weight];
	}

	/*
	dp[j]: the maximal value when the capacity of the bag is j
	dp[j] = max(dp[j]                         // when the i-th product cannot put into the package
				dp[j-weight[i]] + values[i])  // when the i-th product is put into the package
	*/
	int maxValueII(std::vector<int>& values, std::vector<int>& weights, 
		int package_weight) {
		int m = weights.size();
		std::vector<int> dp(package_weight+1, 0);

		for (int i = 0; i <= m; ++i) {
			// reverse order to prevent one product is used many times
			for (int j = package_weight; j>=weights[i]; --j) {
				dp[j] = max(dp[j], dp[j-weights[i]] + values[i]);
			}
		}
		showVec(dp);
		return dp[package_weight];
	}

	/*
	infinite numbers of products
	dp[j] = max(dp[j], dp[j - weights[i]] + values[i] 
	*/
	int maxValueIII(std::vector<int>& values, std::vector<int>& weights, 
		int package_weight) {
		int m = weights.size();
		std::vector<int> dp(package_weight+1, 0);
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= package_weight && j >= weights[i]; ++j) {
				dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
			}
		}
		showVec(dp);
		return dp[package_weight];
	}

	/*
	has number of products
	*/
	int maxValueIV(std::vector<int>& values, std::vector<int>& weights,
			std::vector<int>& nums, int package_weight) {
		std::vector<int> values_all, weights_all;
		for (int j=0; j<nums.size(); ++j) {
			for (int i = 0; i < nums[j]; ++i) {
				/* code */
				values_all.push_back(values[j]);
				weights_all.push_back(weights[j]);
			}
		}
		showVec(values_all);
		showVec(weights_all);
		return maxValueII(values_all, weights_all);
	}


	template<typename T>
	void showVec(std::vector<T>& nums) {
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

	Solution s;
	std::vector<int> values 	= {3,2,5,6,1,4};
	std::vector<int> weights 	= {4,2,1,7,3,6};
	cout << s.maxValueI(values, weights, 21) 	<< endl;
	cout << s.maxValueII(values, weights, 21) 	<< endl;
	cout << s.maxValueIII(values, weights, 21)	<< endl;
	return 0;
}