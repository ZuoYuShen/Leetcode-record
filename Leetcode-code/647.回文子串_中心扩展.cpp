/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i=0; i<2*n-1; i++){
            int L = i/2, R = i/2 + i%2;
            while(L >= 0 && R < n && s[L]==s[R]){
                L--;
                R++;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end