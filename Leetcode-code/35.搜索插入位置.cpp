/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for(int i=0; i<=nums.size(); i++){
            if(nums[i] >= target){
                index = i;
                break;
            }
            else if (nums[nums.size()-1] < target){
                index = nums.size();
                break;
            }    
        }
        return index;
    }
};
// @lc code=end

