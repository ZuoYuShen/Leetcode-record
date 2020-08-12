/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;

        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);

        while(!Q.empty()){
            auto n = Q.front();
            Q.pop();
            for(auto& neighbor: n->neighbors) {
                if(visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    Q.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
// @lc code=end