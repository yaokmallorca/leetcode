#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string intToRoman(int num) {
		// unordered_map<int, char> roman;
		std::vector<char> romans = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
		std::vector<int> numbers = {1000, 500, 100, 50, 10, 5, 1};
		string res = ""; 

		for (int i = 0; i < numbers.size(); i+=2) {
			int input = num / numbers[i];
			if (input < 4) {
				for(int x = input; x>0; --x) res += romans[i];
			} else if (input == 4) {
				res = res + romans[i] + romans[i-1];
			} else if (input > 4 && input < 9) {
				res += romans[i-1];
				for(int x=6; x<=input; ++x) res += romans[i];
			} else if (input == 9) {
				res = res + romans[i] + romans[i-2] ;
			}
			num %= numbers[i];
		}
		return res;
	}
	


};


int main(int argc, char const *argv[])
{
	// MCMXCIV
	int num = 58;
	Solution s;
	string res = s.intToRoman(num);
	cout << res << endl;
	// cout << "MCMXCIV" << endl;
	return 0;
}