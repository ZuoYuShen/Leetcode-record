/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新21点
 */

// @lc code=start
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0) return 1.0;
        vector<double> dp(K+W);
        for(int i=K; i<=N && i<K+W; i++){
            dp[i] = 1.0;
        }
        dp[K-1] = 1.0*min(N-K+1,W)/W;
        for(int i=K-2; i>=0; i--){
            dp[i] = dp[i+1] + (dp[i+1]-dp[i+W+1])/W;
        }
        return dp[0];
    }
};
// @lc code=end

