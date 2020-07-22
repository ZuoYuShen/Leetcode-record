/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值Ⅱ
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = nums.size()-1;
        while(L<R){
            if(nums[L]<nums[R]) break;
            int mid = L + (R-L)/2;
            if(nums[mid]>nums[R]) L = mid+1;
            else if(nums[mid]<nums[R]) R = mid;
            else{
                R -= 1;
            }
        }
        return nums[L];
    }
};
// @lc code=end