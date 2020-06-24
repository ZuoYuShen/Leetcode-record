/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()<=2) return -1;
        int sum = 0;
        int cur_sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        for(int t=0; t<nums.size(); t++){
            if(cur_sum*2 == sum-nums[t]){
                return t;
                break;
            }
            else{
                cur_sum += nums[t];
            }
        }
        return -1;
    }
};
// @lc code=end

