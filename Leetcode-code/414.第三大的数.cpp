/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= max1) max1 = nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=max1 && nums[i]>=max2) max2 = nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=max1 && nums[i]!=max2 && nums[i]>max3) max3 = nums[i];
        }
        if(max3 == LONG_MIN) return max1;
        return max3;
    }
};
// @lc code=end

