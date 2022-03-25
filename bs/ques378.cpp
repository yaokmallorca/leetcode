#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int kthSmallest(std::vector< std::vector<int> > mat, int k) {
		if (k == 1) return mat[0][0];
		int rows = mat.size(), cols = mat[0].size();
		// mid is between the top-left corner and bottom-right corner
		int left = mat[0][0], right = mat.back().back();
		while (left < right) {
			// for each row
			int cnt = 0;
			int mid = left + (right - left) / 2;
			for (int i = 0; i < rows; ++i) {
				/* code */
				// the first greater than mid
				cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin(); 
			}
			if (cnt < k) left = mid + 1;
			else right = mid;
		}
		return left;
	} 
	
};

int main(int argc, char const *argv[])
{
	std::vector< std::vector<int> > mat = {{1,5,9},{10,11,13},{12,13,15}};
	Solution s;
	int res = s.kthSmallest(mat, 8);
	cout << "res: " << res << endl;
	return 0;
}