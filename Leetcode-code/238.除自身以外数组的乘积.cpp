/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> Left(nums.size(), 1);
        vector<int> Right(nums.size(), 1);
        vector<int> Res(nums.size(), 1);
        int left_M = 1;
        int right_M = 1;
        for(int i=1; i<nums.size(); i++){
            left_M *= nums[i-1];
            Left[i] = left_M;
            right_M *= nums[nums.size()-i];
            Right[nums.size()-i-1] *= right_M;
        }
        for(int i=0; i<nums.size(); i++){
            Res[i] = Left[i]*Right[i];
        }
        return Res;
    }
};
// @lc code=end

