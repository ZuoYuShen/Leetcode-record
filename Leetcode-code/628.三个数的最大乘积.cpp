/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max=INT_MIN, sec_max=INT_MIN, thr_max=INT_MIN;
        int min=INT_MAX, sec_min=INT_MAX;
        int flag = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=max){
                thr_max = sec_max;
                sec_max = max;
                max = nums[i];
            }
            else if(nums[i]>=sec_max){
                thr_max = sec_max;
                sec_max = nums[i];
            }
            else if(nums[i]>=thr_max) thr_max = nums[i];
            if(nums[i]<=min){
                sec_min = min;
                min = nums[i];
            }
            else if(nums[i]<=sec_min) sec_min = nums[i];
        }
        if(min*sec_min*max > max*sec_max*thr_max) flag = 1;
        return flag==1? min*sec_min*max : max*sec_max*thr_max;
    }
};
// @lc code=end

