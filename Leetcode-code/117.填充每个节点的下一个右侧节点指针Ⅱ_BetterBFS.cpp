/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针Ⅱ
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        Node* curr = root;
        Node* dummy = new Node;
        while(curr){
            Node* tail = dummy;
            while(curr){
                if(curr->left){
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if(curr->right){
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
            if(tail == dummy) break;
        }
        return root;
    }
};
// @lc code=end