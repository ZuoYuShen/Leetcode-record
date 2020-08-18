/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路经总和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        TreeNode* p = root;
        if(p==nullptr) return false;
        else if(p->left==nullptr && p->right==nullptr) return p->val==sum;
        return hasPathSum(p->left, sum-p->val) || hasPathSum(p->right, sum-p->right);
    }
};