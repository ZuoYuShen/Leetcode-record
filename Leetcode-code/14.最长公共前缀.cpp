/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()) return "";
        string res = strs[0];
        for(int i=1; i<strs.size(); i++){
            res = LCP(res, strs[i]);
            if(!res.size()) break;
        }
        return res;
    }

    string LCP(string& str1, string& str2){
        int length = min(str1.size(), str2.size());
        int index = 0;
        while(index < length && str1[index]==str2[index]){
            ++index;
        }
        return str1.substr(0, index);
    }
};
// @lc code=end

