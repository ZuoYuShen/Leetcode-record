/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表Ⅱ
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i=1; i<m; ++i){
            pre = pre->next;
        }
        head = pre->next;
        for(int i=m; i<n; ++i){
            ListNode* nxt = head->next;
            head->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};
// @lc code=end