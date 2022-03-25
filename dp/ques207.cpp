#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std; 

class Solution
{
public:
	bool canFinish(int numCourses, std::vector< std::vector<int> >& prerequisites) {
		




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
	
	return 0;
}