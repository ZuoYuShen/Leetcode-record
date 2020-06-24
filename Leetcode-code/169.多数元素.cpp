/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_num = 0;
        unordered_map<int,int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]] += 1;
            if(hashmap[nums[i]] > nums.size()/2){
                maj_num = nums[i];
                break;
            }
        }
        return maj_num;
    }
};
// @lc code=end

