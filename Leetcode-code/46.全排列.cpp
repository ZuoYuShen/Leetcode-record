/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> combine;
    unordered_set<int> contained;

    void Backtrack(vector<int>& nums){
        if(combine.size()==nums.size()){
            res.push_back(combine);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!contained.count(nums[i])){
                contained.insert(nums[i]);
                combine.push_back(nums[i]);
                Backtrack(nums);
                contained.erase(nums[i]);
                combine.pop_back();
            }
            else continue;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        Backtrack(nums);
        return res;
    }
};
// @lc code=end

