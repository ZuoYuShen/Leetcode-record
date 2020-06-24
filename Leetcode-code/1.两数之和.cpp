/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int t;
        vector<int> result;
        unordered_map<int, int> Hash;
        for(int i=0;i<nums.size();i++){
            Hash[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            t = target - nums[i];
            if (Hash.count(t) && Hash[t] != i)
            {
                result.push_back(i);
                result.push_back(Hash[t]);
                break;
            }    
        }
        return result;
    }
};
// @lc code=end

