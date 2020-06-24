/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Max_interval_value = nums[0];
        int MaxSum = nums[0];
        for(int i=1; i<nums.size(); i++){
            Max_interval_value = max(Max_interval_value+nums[i], nums[i]);
            MaxSum = max(MaxSum, Max_interval_value);
        }
        return MaxSum;
    }
};
// @lc code=end

