// Compiler made by *IMRAN KHALID*
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) { return findMedianSortedArrays(nums2, nums1); }
        if (len1 == 0) { 
            if(len2 == 1){return double(nums2[0]);}
            else{
                if(len2%2 == 0)
                    return double((nums2[len2/2-1] + nums2[len2/2])/2.f);
                else
                    return double(nums2[len2/2]);
            }
        }
        int len = len1 + len2;
        if (nums1[len1-1] < nums2[0]) {
            vector<int> total = nums1;
            total.insert(total.end(), nums2.begin(), nums2.end());
            if (len%2 == 0) {
                return double((total[int(len/2)-1] + total[int(len/2)])/2.f);
            } else {
                return double(total[int(len/2)]);
            }        
        }
        int startk_1=0, endk_1=len1;
        int cut1=0, cut2=0;
        while (startk_1 < endk_1){
            cut1 = (endk_1 - startk_1) / 2 + 1;
            cut2 = int(len/2) - cut1 - 1;
            int L1 = (cut1-1)<0? INT_MIN : nums1[cut1-1];
            int R1 = cut1>=len1? INT_MAX : nums1[cut1];
            int L2 = (cut2-1)<0? INT_MIN : nums2[cut2-1];
            int R2 = cut2>=len2? INT_MAX : nums2[cut2];
            cout<<"cut1: "<<cut1<<" cut2: "<<cut2<<endl;
            cout<<"startk_1: "<<startk_1<<" endk_1: "<<endk_1<<endl;
            cout<<"L1: "<<L1<<" R1: "<<R1<<" L2: "<<L2<<" R2: "<<R2<<endl; 
            cout<<"startk_1: "<<startk_1<<" endk_1: "<<endk_1<<endl;
            
            if (L1 > R2) {endk_1 = cut1 - 1;}
            else if (L2 > R1) {startk_1 = cut1 + 1;}
            else {
                if (len%2 == 0) {
                    return float((max(L1, L2) + min(R1, R2))/2.f);
                } else {
                    return float(min(R1, R2));   
                }
            }
            cout<<"######################"<<endl;
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    vector<int> nums1;
    nums1.push_back(2);
    // nums1.push_back(7);
    // nums1.push_back(9);
    
    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(4);
    
    float ret = solution.findMedianSortedArrays(nums1, nums2);
    cout << "median: " << ret << endl;
}