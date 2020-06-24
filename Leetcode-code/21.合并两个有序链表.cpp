/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* res_p = res;
        ListNode* l1_p = l1;
        ListNode* l2_p = l2;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        while(l1_p->next != NULL) l1_p = l1_p->next;
        while(l2_p->next != NULL) l2_p = l2_p->next;
        l1_p->next = new ListNode(-1);
        l2_p->next = new ListNode(-1);
        while(l1->next != NULL && l2->next != NULL){
            if(l1->val < l2->val){
                res_p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                res_p->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            res_p = res_p->next;
        }
        if(l1->next==NULL){
            while(l2->next != NULL){
                res_p->next = new ListNode(l2->val);
                l2 = l2->next;
                res_p = res_p->next;
            }
        }
        if(l2->next==NULL){
            while(l1->next != NULL){
                res_p->next = new ListNode(l1->val);
                l1 = l1->next;
                res_p = res_p->next;
            }
        }
        return res->next;
    }
};
// @lc code=end

