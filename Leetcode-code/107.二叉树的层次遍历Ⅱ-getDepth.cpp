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
    int getDepth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int Depth = getDepth(root);
        res.resize(Depth);
        queue<TreeNode*> order;
        order.push(root);
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
            res[Depth-1] = cur;
            Depth -= 1;
        }
        return res;
    }
};
// @lc code=end