/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int count = 1;
        bool flag = true;
        while(!Q.empty()) {
            int n = Q.size();
            for(int i=0; i<n; i++){
                TreeNode* tmp = Q.front();
                Q.pop();
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);
                if(!tmp.left && !tmp.right){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            ++count;
        }
        return count;
    }
};
// @lc code=end