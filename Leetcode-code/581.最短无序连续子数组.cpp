/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums = nums;
        std::sort(snums.begin(), snums.end());
        int left_index = nums.size();
        int right_index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != snums[i]){
                left_index = i < left_index ? i : left_index;
                right_index = i > right_index ? i : right_index;
            }
        }
        return right_index >= left_index ? right_index - left_index + 1 : 0;
    }
};
// @lc code=end

