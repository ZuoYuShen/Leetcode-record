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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> order;
        vector<int> res;
        TreeNode* p = root;
        while(p || !order.empty()){
            while(p){
                order.push(p);
                p = p->left;
            }
            p = order.top();
            order.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};
// @lc code=end 