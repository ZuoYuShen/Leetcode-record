/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历Ⅱ
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> order;
        order.push(root);
        stack<vector<int>> tmp;
        while(!order.empty()){
            int n = order.size();
            vector<int> cur;
            for(int i=0; i<n; i++){
                TreeNode* p = order.front();
                order.pop();
                if(p->left) order.push(p->left);
                if(p->right) order.push(p->right);
                cur.push_back(p->val);
            }
            tmp.push(cur);
        }
        while(!tmp.empty()){
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};
// @lc code=end