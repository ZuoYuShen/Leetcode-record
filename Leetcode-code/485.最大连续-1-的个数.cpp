/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int Max_count = 0;
        //if(nums.size()==1) return nums[0]==0?0:1;
        for(int i=0; i<nums.size(); i++){
            nums[i] == 1 ? Max_count=max(Max_count, ++count) : count=0;
            //if(nums[i] == 1){
                // count++;
                //Max_count = max(Max_count, count);
            //}
            //if(nums[i] == 0){
                // Max_count = max(Max_count, count);
                //count = 0;
            //}
        }
        return Max_count;
    }
};
// @lc code=end

