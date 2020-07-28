/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode* build(vector<int>& preorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if(preorder_left > preorder_right) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorder_left]);
        int left_length = inorder_hash[preorder[preorder_left]] - inorder_left;
        root->left = build(preorder, preorder_left+1, preorder_left+left_length, inorder_left, inorder_left+left_length-1);
        root->right = build(preorder, preorder_left+1+left_length, preorder_right, inorder_left+1+left_length, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() || !inorder.size()) return nullptr;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inorder_hash[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, n-1, 0, n-1);
        return root;
    }
};
// @lc code=end