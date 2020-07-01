/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m, vector<int>(n));
        int res = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(A[i]==B[j]){
                    if(i==0 || j==0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end