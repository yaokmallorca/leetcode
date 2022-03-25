#include <stdlib.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int n = values.size();
		int mx = 0, res = 0;

		for (int i = 0; i < n; ++i) {
			/* code */
			res = max(res, mx + values[i] - i);
			mx = max(mx, values[i] + i);
		}
		return res;
	}
};

int main(int argc, char const *argv[]) {
	std::vector<int> values = {8,1,5,2,6};
	Solution s;
	cout << s.maxScoreSightseeingPair(values) << endl;

	return 0;
}