/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> inorder_hash;

    TreeNode* build(vector<int>& postorder, int inorder_left, int inorder_right, int post_left, int post_right) {
        if(inorder_left > inorder_right) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_right]);
        int left_length = inorder_hash[postorder[post_right]] - inorder_left;
        root->left = build(postorder, inorder_left, inorder_left+left_length-1, post_left, post_left+left_length-1);
        root->right = build(postorder, inorder_left+left_length+1, inorder_right, post_left+left_length, post_right-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size()) return nullptr;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorder_hash[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, 0, n-1, 0, n-1);
        return root;
    }
};
// @lc code=end
