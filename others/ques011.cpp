#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxArea(std::vector<int>& waters) {
		int res=-1, left=0, right=waters.size()-1;
		while(left < right) {
			int area = (right - left) * (waters[left] > waters[right] ? waters[right] : waters[left]);
			res = max(res, area);
			if (waters[left] < waters[right]) ++left;
			else --right;
		}
		return res;
	}
	
};


int main(int argc, char const *argv[])
{
	std::vector<int> waters = {1,8,6,2,5,4,8,3,7};
	Solution s;
	int result = s.maxArea(waters);
	cout << "result: " << result << endl;
	return 0;
}