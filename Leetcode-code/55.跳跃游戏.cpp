/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums){
        int cur = nums.size()-1;
        for(int k=nums.size()-2; k>=0; k--){
            if(nums[k] >= cur-k) cur = k;
        }
        if(cur==0) return true;
        return false;
    }
};
// @lc code=end