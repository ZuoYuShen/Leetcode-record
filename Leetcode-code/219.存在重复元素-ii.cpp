/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i=0; i<nums.size(); i++){
            if(count.count(nums[i]) != NULL && i-count[nums[i]]<=k) return true;
            count[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

