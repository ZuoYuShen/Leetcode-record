/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树Ⅱ
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> construct(int start, int end){
        vector<TreeNode*> ret;
        if(start > end) ret.push_back(nullptr);
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = construct(start, i-1);
            vector<TreeNode*> right = construct(i+1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    ret.push_back(cur);
                }
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        res = construct(1,n);
        return res;
    }
};
// @lc code=end