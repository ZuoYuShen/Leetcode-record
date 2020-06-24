/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastupIndex = 0;
        int found = 0;
        for(int i=0; i+1<nums.size(); i++){
            if(nums[i]<nums[i+1]){
                found = 1;
                lastupIndex = max(lastupIndex, i);
            }
        }
        if(found==1){
            int exchangeIndex = lastupIndex+1;
            for(int i=lastupIndex+2; i<nums.size(); i++){
                if(nums[i]>nums[lastupIndex]) exchangeIndex = i; 
            }
            int temp = nums[lastupIndex];
            nums[lastupIndex] = nums[exchangeIndex];
            nums[exchangeIndex] = temp;
            if(lastupIndex<nums.size()-2) std::sort(nums.begin()+lastupIndex+1, nums.end());
        }
        if(found==0) std::sort(nums.begin(),nums.end());
    }
};
// @lc code=end

