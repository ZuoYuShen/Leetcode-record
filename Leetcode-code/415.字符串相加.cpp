/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1, j=num2.size()-1, add=0;
        int res_num, x, y;
        string res;
        while(i>=0 || j>=0 || add!=0){
            x = i>=0 ? num1[i]-'0' : 0;
            y = j>=0 ? num2[j]-'0' : 0;
            res_num = x + y + add;
            res += ('0' + res_num%10);
            add = res_num/10;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end