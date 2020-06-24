/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combine;

    void Backtrack(vector<int>& nums, unordered_map<int, int>& contained){
        if(combine.size()==nums.size()){
            res.push_back(combine);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(contained[nums[i]]==0) continue;
            if(contained[nums[i]]>0){
                contained[nums[i]] -= 1;
                combine.push_back(nums[i]);
                Backtrack(nums, contained);
                contained[nums[i]] += 1;
                combine.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> contained;
        for(int i=0; i<nums.size(); i++){
            if(!contained.count(nums[i])) contained[nums[i]] = 1;
            else contained[nums[i]] += 1;
        }
        Backtrack(nums, contained);
        return res;
    }
};
// @lc code=end

