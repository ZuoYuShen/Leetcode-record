/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        int N = 1;
        int count = 1;
        if(p->next==NULL) return NULL;
        while(p->next != NULL){
            p = p->next;
            N += 1;
        }
        if(N==n) return head->next;
        p = head;
        while(p->next->next != NULL && p->next != NULL){
            if(count+1!=N+1-n){
                p = p->next;
            }
            if(count+1==N+1-n){
                p->next = p->next->next;
            }
            count++;  
        }
        if(n==1) p->next = NULL;
        return head;
    }
};
// @lc code=end

