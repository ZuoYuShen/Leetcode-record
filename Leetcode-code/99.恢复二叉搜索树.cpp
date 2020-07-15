/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void travel(TreeNode* root, TreeNode*& pre, vector<TreeNode*>& exchange, int& flag) {
        if(root==nullptr) return;
        travel(root->left, pre, exchange, flag);
        if(root->val < pre->val){
            if(flag==0){
                exchange.push_back(pre);
                exchange.push_back(root);
            }
            else{
                exchange.pop_back();
                exchange.push_back(root);
            }
            flag++;
        }
        pre = root; 
        travel(root->right, pre, exchange, flag);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* p = root;
        vector<TreeNode*> exchange;
        TreeNode* pre = new TreeNode(INT_MIN);
        int flag = 0;
        travel(p, pre, exchange, flag);
        int temp = exchange[0]->val;
        exchange[0]->val = exchange[1]->val;
        exchange[1]->val = temp;
    }
};
// @lc code=end