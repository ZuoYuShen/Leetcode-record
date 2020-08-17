/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if(!root->left || !root->right) return left_depth + right_depth + 1;
        return 1 + min(left_depth, right_depth);
    }
};
// @lc code=end