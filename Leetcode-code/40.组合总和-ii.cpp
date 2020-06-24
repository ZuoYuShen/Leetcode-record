/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    int cur_sum = 0;

    void DFS(int start, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> cur, int cur_sum){
        if(cur_sum==target){
            sort(cur.begin(), cur.end());
            if(!res.size()) res.push_back(cur);
            else{
                int flag = 0;
                for(int i=0; i<res.size(); i++){
                    if(res[i]==cur) flag=1;
                }
                if(flag==0) res.push_back(cur);
            }
            return;
        }
        if(cur_sum>target) return;
        if(start==candidates.size()) return;
        for(int i=start; i<candidates.size(); i++){
            cur.push_back(candidates[i]);
            DFS(i+1, candidates, target, res, cur, cur_sum+candidates[i]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(!candidates.size()) return res;
        DFS(0, candidates, target, res, cur, cur_sum);
        return res;
    }
};
// @lc code=end

