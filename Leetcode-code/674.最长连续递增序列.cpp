/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int count = 1;
        int Max_count = 1;
        for(int i=1; i<nums.size(); i++){
            nums[i-1]<nums[i] ? count++ : count = 1;
            //if(nums[i-1]<nums[i]){
            //    count++;
            //}
            //else{
            //    count = 1;
            //}
            Max_count = max(Max_count, count);
        }
        return Max_count;
    }
};
// @lc code=end

