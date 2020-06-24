/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> hash_map;
        int max_num_freq = 0, length;
        for(int i=0; i<nums.size(); i++) hash_map[nums[i]].push_back(i);
        for(auto i:hash_map){
            int cur_num_freq_size = i.second.size();
            int cur_length = i.second[cur_num_freq_size-1] - i.second[0] + 1;
            if(cur_num_freq_size >= max_num_freq){
                int cur_length = i.second[cur_num_freq_size-1] - i.second[0] + 1;
                if(cur_num_freq_size > max_num_freq){
                    max_num_freq = cur_num_freq_size;
                    length = cur_length;
                }
                else{
                    length = min(cur_length, length);
                }
            }
            
        }
        return length;
    }
};
// @lc code=end

