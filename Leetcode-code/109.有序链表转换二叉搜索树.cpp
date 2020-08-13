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
    TreeNode* build(ListNode* head, ListNode* tail){
        if(head == tail) return nullptr;
        ListNode* p = head, *q = head;
        while(q != tail && q->next!= tail){
            p = p->next;
            q = q->next->next;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = build(head, p);
        root->right = build(p->next, tail);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
};
// @lc code=end