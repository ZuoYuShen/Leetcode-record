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
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j=0; j<n; j++){
            for(int i=0; i<=j; i++){
                if(s[i]==s[j]){
                    if(i==j || j-i==1 || dp[i+1][j-1]==1){
                        dp[i][j] = 1;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end