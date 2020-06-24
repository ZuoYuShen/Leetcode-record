/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int flag = 0;
        if (nums.size()==0){
            return nums.size();
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[flag++] = nums[i];
            }    
        }
        return flag;
    }
};
// @lc code=end

