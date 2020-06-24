/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int k=1; k<nums.size(); k++){
            if(nums[k-1]>nums[k]){
                if(k-2>=0 && nums[k-2]>nums[k]){
                    nums[k] = nums[k-1];
                }
                else{
                    nums[k-1] = nums[k];
                }
                count++;
            }
        }
        return count <= 1;
    }
};
// @lc code=end

