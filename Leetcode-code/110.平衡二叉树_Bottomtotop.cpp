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
    bool helper(TreeNode* root, int& depth) {
        if(root == nullptr){
            depth = 0;
            return true;
        }
        int left_depth;
        int right_depth;
        if(helper(root->left, left_depth) && helper(root->right, right_depth) && abs(left_depth - right_depth) < 2){
            depth = 1 + max(left_depth, right_depth);
            return true;
        }
        return false; 
    }

    bool isBalanced(TreeNode* root) {
        int depth;
        return helper(root, depth);
    }
};
// @lc code=end 