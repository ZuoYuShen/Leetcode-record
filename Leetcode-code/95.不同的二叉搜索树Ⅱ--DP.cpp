/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树Ⅱ
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
    TreeNode* clone(TreeNode* root){
        if(root==nullptr) return nullptr;
        TreeNode* copy = new TreeNode(root->val);
        copy->left = clone(root->left);
        copy->right = clone(root->right);
        return copy;
    }

    vector<TreeNode*> generateTrees(int n){
        if(n==0) return {};
        vector<vector<TreeNode*>> dp(n+1);
        dp[1].push_back(new TreeNode(1));
        for(int i=2; i<=n; i++){
            for(TreeNode* tree : dp[i-1]){
                TreeNode* dummy = clone(tree);
                int level = 0;
                while(dummy){
                    TreeNode* cloneTree = clone(tree);
                    TreeNode* root = cloneTree;
                    int count = level;
                    while(count--) cloneTree = cloneTree->right;
                    TreeNode* newRight = new TreeNode(i);
                    TreeNode* oldRight = clone(dummy->right);
                    newRight->left = oldRight;
                    cloneTree->right = newRight;
                    dp[i].push_back(root);

                    dummy = dummy->right;
                    level++;
                }
                
                TreeNode* newRoot = new TreeNode(i);
                newRoot->left = tree;
                dp[i].push_back(newRoot);
            }
        }
        return dp[n];
    }
};
// @lc code=end