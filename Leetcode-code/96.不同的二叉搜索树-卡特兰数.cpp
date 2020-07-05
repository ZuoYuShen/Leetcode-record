/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n){
        long res = 1;
        for(int i=0; i<n; i++){
            res = res * 2 * (2*i+1) / (i+2);
        }
        return (int) res;
    }
};
// @lc code=end