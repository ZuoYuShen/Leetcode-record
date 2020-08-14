/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 二叉树的层次遍历Ⅱ
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
    int depth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        bool flag;
        if(left_depth - right_depth > 1 || left_depth - right_depth < -1) flag = false;
        else flag = true;
        return flag && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end 