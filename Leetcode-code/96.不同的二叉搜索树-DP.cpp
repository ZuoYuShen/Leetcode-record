/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n){
        vector<int> res(n+1, 0);
        res[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                res[i] += res[j-1]*res[i-j];
            }
        }
        return res[n];
    }
};
// @lc code=end