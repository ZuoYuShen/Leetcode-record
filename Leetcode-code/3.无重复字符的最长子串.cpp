/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1) return s.size();
        unordered_map<char, int> Hash_map;
        int Max_count = 0;
        int cur_count = 0;
        int i=0;
        int cur_point = 0;
        while(i<s.size()){
            if(Hash_map[s[i]]){
                cur_point = max(cur_point, Hash_map[s[i]]);
                cur_count = i+1-cur_point;
            }
            else{
                cur_count++;
            }
            Hash_map[s[i++]] = i+1;
            Max_count = max(Max_count, cur_count);
        }
        return Max_count;
    }
};
// @lc code=end

