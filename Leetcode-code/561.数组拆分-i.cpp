/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0) sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end

