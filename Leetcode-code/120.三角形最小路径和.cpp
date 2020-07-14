/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        int res = INT_MAX;
        vector<vector<int>> sum(n, vector<int>(n));
        sum[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; i++){
                if(j==0) sum[i][j] = sum[i-1][j] + triangle[i][j];
                else if(j==i) sum[i][j] = sum[i-1][j-1] + triangle[i][j];
                else sum[i][j] = triangle[i][j] + min(sum[i-1][j], sum[i-1][j-1]);
            }
        }
        for(int j=0; j<n; j++){
            if(sum[n-1][j] < res) res = sum[n-1][j];
        }
        return res;
    }
};
// @lc code=end