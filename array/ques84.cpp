#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int largestRectangleArea_bf(std::vector<int>& heights) {
		// area[i] = min(height[i-1], height[i]) * 2
		int res = 0, n = heights.size();
		for (int i = 0; i < n; ++i) {
			/* code */
			int left = max(0, i-1), right = min(n-1, i+1);
			int min_val = INT_MAX;
			while (left >= 0) {
				min_val = min(heights[i], heights[left]);
				res = max(res, min_val * (i - left));
				--left;
			}
			min_val = INT_MAX;
			while (right < n) {
				min_val = min(heights[i], heights[right]);
				res = max(res, min_val * (right - i));
				++right;
			}
		}	
		return res;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> heights =  {2, 1, 5, 6, 2, 3};
	Solution s;
	cout << s.largestRectangleArea_bf(heights) << endl; 
	return 0;
}