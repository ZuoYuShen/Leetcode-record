/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> BFS;
        BFS.push(root);
        while(!BFS.empty()){
            int n = BFS.size();
            vector<int> tmp;
            for(int i=0; i<n; i++){
                TreeNode* cur = BFS.front();
                tmp.push_back(cur->val);
                BFS.pop();
                if(cur->left) BFS.push(cur->left);
                if(cur->right) BFS.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end