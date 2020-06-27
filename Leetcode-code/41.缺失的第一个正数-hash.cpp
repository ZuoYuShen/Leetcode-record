/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=0) nums[i] = nums.size() + 1;
        }
        for(int i=0; i<nums.size(); i++){
            int x = abs(nums[i]);
            if(x <= nums.size()){
                nums[x-1] = -abs(nums[x-1]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }
};
// @lc code=end