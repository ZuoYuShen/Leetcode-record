/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int i=0; i<nums.size(); i++){
            num_set.insert(nums[i]);
        }
        //for(const int& num : nums){
        //    num_set.insert(num);
        //}
        int res = 0;
        for(int num : num_set){
            if(!num_set.count(num-1)){
                int currentNum = num;
                int cur_length = 1;
                while(num_set.count(currentNum + 1)){
                    currentNum += 1;
                    cur_length += 1;
                }
                res = max(res, cur_length);
            }
        }
        return res;
    }
};
// @lc code=end

