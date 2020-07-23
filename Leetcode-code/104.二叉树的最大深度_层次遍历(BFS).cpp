/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> order;
        order.push(root);
        int level = 0;
        while(!order.empty()){
            int n = order.size();
            for(int i=0; i<n; i++){
                TreeNode* p = order.front();
                order.pop();
                if(p->left) order.push(p->left);
                if(p->right) order.push(p->right);
            }
            level += 1;
        }
        return level;
    }
};
// @lc code=end