/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> order;
        int flag = 1;
        order.push_front(root->val);
        while(!order.empty()){
            int n = order.size();
            vector<int> cur;
            if(flag==1){
                for(int i=0; i<n; i++){
                    TreeNode* p = order.front();
                    order.pop_front();
                    if(p->left) order.push_back(p->left);
                    if(p->right) order.push_back(p->right);
                    cur.push_back(p->val);
                }
            }
            else{
                for(int i=0; i<n; i++){
                    TreeNode* p = order.back();
                    order.pop_back();
                    if(p->right) order.push_front(p->right);
                    if(p->left) order.push_front(p->left);
                    cur.push_back(p->val);
                }
            }
            res.push_back(cur);
            flag *= -1;
        }
        return res;
    }
};
// @lc code=end