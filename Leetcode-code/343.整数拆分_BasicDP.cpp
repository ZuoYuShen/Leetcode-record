/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i/2; j++){
                int cur_max = max(j*(i-j), j*dp[i-j]);
                dp[i] = max(dp[i], cur_max);
            }
        }
        return dp[n];
    }
};
// @lc code=end