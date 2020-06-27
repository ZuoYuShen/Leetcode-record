/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==res) res += 1;
            else if(nums[i]>res) break;
        }
        return res;
    }
};
// @lc code=end