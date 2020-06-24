/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int max_value = 0;
        int max_index = 0;
        int sec_max_value = 0;
        for(int i=0; i<nums.size(); i++){
            if (nums[i]>max_value){
                sec_max_value = max_value;  //important
                max_value = nums[i];
                max_index = i;
            }
            else if(nums[i]>sec_max_value){
                sec_max_value = nums[i];
            }
        }
        return max_value >= 2*sec_max_value ? max_index : -1;
    }
};
// @lc code=end

