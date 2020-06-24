/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int siz;

    void dfs(int now, int sum, int target, vector<int>& num){
        if(sum > target) return;
        if(sum == target){
            ans.push_back(tmp);
            return;
        }
        for(int i=now; i<siz; i++){
            tmp.push_back(num[i]);
            dfs(i, sum+num[i], target, num);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        siz = candidates.size();
        dfs(0, 0, target, candidates);
        return ans;
    }
};
// @lc code=end

