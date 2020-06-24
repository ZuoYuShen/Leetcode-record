/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if(numRows==1) return s;
        string res;
        vector<string> collect(numRows);
        int L = 0;
        int R = 2*numRows - 2;
        int cur = 0;
        int flag = -1;
        for(int i=0; i<s.size(); i++){
            collect[cur] += s[i];
            if(cur==0 || cur==numRows-1) flag = -flag;
            cur += flag;
        }
        for(int i=0; i<numRows; i++) res += collect[i];
        return res;
    }
};
// @lc code=end

