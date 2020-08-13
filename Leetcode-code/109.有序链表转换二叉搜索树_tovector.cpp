/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(int L, int R, vector<int>& nums){
        if(L > R) return nullptr;
        int mid = L + (R-L)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(L, mid-1, nums);
        root->right = build(mid+1, R, nums);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> nums;
        ListNode* p = head;
        while(p->next != nullptr){
            nums.push_back(p->val);
            p = p->next;
        }
        nums.push_back(p->val);
        int L = 0, R = nums.size()-1;
        TreeNode* res = build(L, R, nums);
        return res;
    }
};
// @lc code=end