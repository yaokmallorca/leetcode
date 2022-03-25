#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <map>
#include <utility> // pair

using namespace std;

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector< std::vector<int> >& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        std::vector<int> res;
        int up=0, left=0, down=rows-1, right=cols-1;
        while(true) {
            for(int i=left; i<=right; ++i)
                res.push_back(matrix[up][i]);
            ++up;
            if (up > down) break;
            for(int i=up; i<=down; ++i) 
                res.push_back(matrix[i][right]);
            --right;
            if (right < left) break;
            for(int i=right; i>=left; --i)
                res.push_back(matrix[down][i]);
            --down;
            if (up > down) break;
            for(int i=down; i>=up; --i)
                res.push_back(matrix[i][left]);
            ++left;
            if (right < left) break;
        }
        return res;
    }
    
    void showVec(std::vector<int> nums) {
        for (auto num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    void showVec(std::vector< std::vector<int> > mat) {
        for (auto row : mat) {
            showVec(row);
        }
    }
};

int main() {
    Solution s;

    std::vector< std::vector<int> > matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    s.showVec(matrix);
    std::vector<int> results = s.spiralOrder(matrix);
    s.showVec(results);
    return 0;
}