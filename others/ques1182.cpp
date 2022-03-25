#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<int> shortestDistanceColor(std::vector<int>& colors, std::vector< std::vector<int> >& queries) {



	}
	
	void showVector(std::vector<int> nums) {
		for (auto num : nums) {
			cout << num << " ";
		}
		cout << endl;
	}

	void showVector(std::vector< std::vector<int> > nums) {
		for (auto vec : nums) {
			showVector(vec);
		}

	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> colors = {1,1,2,1,3,2,2,3,3};
	std::vector< std::vector<int> > queries = {{1,3},{2,2},{6,1}};
	Solution s;
	s.showVector(queries);

	return 0;
}