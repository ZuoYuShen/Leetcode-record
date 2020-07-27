/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int cur_index = 0;
        for(int i=0; i<n; i++){
            bool found = false;
            for(int j=cur_index; j<t.size(); j++){
                if(s[i]==t[j]){
                    cur_index = j+1;
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};
// @lc code=end