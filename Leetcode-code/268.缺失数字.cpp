/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned long sum1 = nums.size()*(nums.size()+1)/2;
        unsigned long sum2 = 0;
        for(int i=0; i<nums.size(); i++){
            sum2 += nums[i];
        }
        int result = sum1 - sum2;
        return result;
    }
};
// @lc code=end

