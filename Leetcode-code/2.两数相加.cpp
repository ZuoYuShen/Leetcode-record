/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* res_p = res;
        bool carry = false;
        int sum = 0;
        while(l1 != NULL || l2 != NULL){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry) sum++;
            carry = sum>=10 ? true : false;
            res_p->next = new ListNode(sum%10);
            res_p = res_p->next;
        }
        if(carry){
            res_p->next = new ListNode(1);
        }
        return res->next;
    }
};
// @lc code=end

