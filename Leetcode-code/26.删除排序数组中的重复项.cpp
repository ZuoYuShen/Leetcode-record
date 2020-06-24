/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        if (nums.size() < 2){
            return nums.size();
        }
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                length += 1;
                nums[length] = nums[i+1];
            }
        }
        return length+1;           
    }
};
// @lc code=end

