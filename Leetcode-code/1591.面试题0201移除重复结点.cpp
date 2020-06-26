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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==NULL) return head;
        unordered_set<int> Num;
        ListNode* p = head;
        Num.insert(p->val);
        while(p->next!=NULL){
            if(Num.count(p->next->val)){
                p->next = p->next->next;
                continue;
            }
            else{
                Num.insert(p->next->val);
                p = p->next;
            }
        }
        return head;
    }
}; 
