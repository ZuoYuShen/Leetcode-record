/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
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

