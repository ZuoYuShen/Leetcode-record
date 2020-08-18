/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路经总和Ⅱ
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
    void helper(TreeNode* root, int target, vector<int>& tmp, vector<vector<int>>& res) {
        if(!root) return;
        if(!root->left && !root->right){
            tmp.push_back(root->val);
            if(root->val == target){
                res.push_back(tmp);
            }
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        helper(root->left, target - root->val, tmp, res);
        helper(root->right, target - root->val, tmp, res);
        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        vector<vector<int>> res;
        helper(root, sum, tmp, res);
        return res;
    }
};
// @lc code=end