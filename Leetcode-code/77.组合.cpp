/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void Backtrack(int n, int k, int start, vector<vector<int>>& res, vector<int>& cur){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }
        if(n-start+1+cur.size() < k) return;
        for(int i=start; i<=n; i++){
            cur.push_back(i);
            Backtrack(n, k, i+1, res, cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        Backtrack(n, k, 1, res, cur);
        return res;
    }
};
// @lc code=end