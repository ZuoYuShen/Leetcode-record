/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void getValue(vector<int>& res, TreeNode* root){
        if(root==nullptr) return;
        getValue(res, root->left);
        res.push_back(root->val);
        getValue(res, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        getValue(res, root);
        return res;
    }
}; 