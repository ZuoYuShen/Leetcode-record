/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        unordered_set<int> Num;
        ListNode* p = head;
        Num.insert(p->val);
        while(p->next != NULL){
            if(Num.count(p->next->val)){
                p->next = p->next->next;
            }
            else{
                Num.insert(p->next->val);
                p = p->next;
            }
        }
        return head;
    }
};
// @lc code=end