/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        int count = 0;
        if(nums.size()<=1 || k<0) return 0;
        if(k==0){
            for(int i=0; i<nums.size(); i++){
                count_map[nums[i]] += 1;
                if(count_map[nums[i]] == 2) count++;
            }
            return count;
        }
        for(int i=0; i<nums.size(); i++){
            count_map[nums[i]] = 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(count_map.find(nums[i]-k) != count_map.end()){
                if(count_map[nums[i]]==0){
                    count++;
                    count_map[nums[i]] = 1;
                }
            }
        }
        return count;
    }
};
// @lc code=end

