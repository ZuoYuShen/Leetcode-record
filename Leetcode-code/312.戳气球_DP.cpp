/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        vector<int> val;
        val.resize(n+2);
        for(int i=1; i<=n; i++){
            val[i] = nums[i-1];
        }
        val[0] = 1;
        val[n+1] = 1;
        for(int dis=2; dis<=n+1; dis++){
            for(int i=0; i+dis<=n+1; i++){
                int max = 0;
                for(int k=i+1; k<i+dis; k++){
                    int val_k = dp[i][k] + dp[k][i+dis] + val[i]*val[k]*val[i+dis];
                    if(val_k > max) max = val_k;
                }
                dp[i][i+dis] = max;
            }
        }
        return dp[0][n+1];
    }
};
// @lc code=end