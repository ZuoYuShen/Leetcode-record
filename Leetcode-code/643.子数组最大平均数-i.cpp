/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        double sumMax = sum;
        for(int i=k; i<nums.size(); i++){
            sum += nums[i] - nums[i-k];
            sumMax = sumMax > sum ? sumMax : sum;
        }
        return sumMax/k;
    }
};
// @lc code=end

