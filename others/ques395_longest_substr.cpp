#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>


class Solution
{
private:
    /* data */
public:
    Solution(){};
    ~Solution(){};

    int longestSubstring_slow(std::string s, int k) {
        int res=0, i=0, n=s.size();
        while (i+k <= n) {
            int m[26]={0}, mask=0, max_idx=i;
            for(int j=i; j<n; ++j) {
                int t = s[j] - 'a';
                ++m[t];
                if (m[t]<k) mask |= (1<<t);
                else mask &= (~(1 << t));
                if (mask == 0) {
                    res = std::max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }

    int longestSubstring(std::string s, int k) {
        int res = 0, n = s.size();
        for (int cnt = 1; cnt <= 26; ++cnt) {
            int start = 0, i = 0, uniqueCnt = 0;
            std::vector<int> charCnt(26);
            while (i < n) {
                bool valid = true;
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = std::max(res, i - start);
            }
        }    
        return res;

    }
};

int main(int argc, char const *argv[])
{
    std::string str = "ababbc"; // "aaabb";
    int k = 2;
    Solution s;

    int res = s.longestSubstring(str, k);
    std::cout << "longestSubstring results: " << res << std::endl;
    return 0;
}
