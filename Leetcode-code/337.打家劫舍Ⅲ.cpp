/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍Ⅲ
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
    pair<int, int> robber(TreeNode* root) {
        if(!root) return {0, 0};
        pair<int, int> left = robber(root->left);
        pair<int, int> right = robber(root->right);
        int max_coin = max(left.first, left.second) + max(right.first, right.second);
        return {root->val + left.second + right.second, max_coin};
    }

    int rob(TreeNode* root) {
        pair<int, int> res = robber(root);
        return max(res.first, res.second);
    }
};
// @lc code=end