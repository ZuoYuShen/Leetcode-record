/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集Ⅱ
 */

// @lc code=start
class Solution {
public:
    void Backtrack(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& cur_set){
        if(cur_set.size()>0){
            res.push_back(cur_set);
        }
        for(int i=start; i<nums.size(); i++){
            if(i>start){
                if(nums[i]==nums[i-1]) continue;
            }
            cur_set.push_back(nums[i]);
            Backtrack(nums, i+1, res, cur_set);
            cur_set.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur_set;
        res.push_back(cur_set);
        Backtrack(nums, 0, res, cur_set);
        return res;
    }
};
// @lc code=end