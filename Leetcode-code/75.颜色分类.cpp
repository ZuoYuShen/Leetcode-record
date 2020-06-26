/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = nums.size()-1;
        int curr = 0;
        while(curr <= p2){
            if(nums[curr]==0){
                int temp = nums[p1];
                nums[p1] = nums[curr];
                nums[curr] = temp;
                p1 += 1;
                curr += 1;
            }
            else if(nums[curr]==2){
                int temp = nums[p2];
                nums[p2] = nums[curr];
                nums[curr] = temp;
                p2 -= 1;
            }
            else curr += 1;
        }
    }
};
// @lc code=end