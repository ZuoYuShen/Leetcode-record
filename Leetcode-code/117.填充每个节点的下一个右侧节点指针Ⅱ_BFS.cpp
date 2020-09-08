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
        if(root==nullptr) return nullptr;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            for(int i=0; i<n; i++){
                Node* p = Q.front();
                Q.pop();
                if(i<n-1) p->next = Q.front();
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
        }
        return root;
    }
};
// @lc code=end