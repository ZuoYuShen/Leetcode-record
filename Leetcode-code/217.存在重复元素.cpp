/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
            if (count[nums[i]] >= 2){
                return true;
                break;
            }    
        }
        return false;
    }
};
// @lc code=end

