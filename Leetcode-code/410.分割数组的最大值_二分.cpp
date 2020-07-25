/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long low = nums[0];
        long high = 0;
        for(int i=0; i<n; i++){
            high += nums[i];
            low = low>nums[i] ? low : nums[i];
        }
        while(low<high){
            long mid = low + (high-low)/2;
            int count = 1;
            long sub_sum = 0;
            for(int i=0; i<n; i++){
                sub_sum += nums[i];
                if(sub_sum > mid){
                    count += 1;
                    sub_sum = nums[i];
                }
            }
            if(count > m) low = mid+1;
            else high = mid;
        }
        return (int)low;
    }
};
// @lc code=end