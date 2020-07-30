/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) return n-1;
        int m = n/3;
        int res = n%3;
        if(res==2) return (int)pow(3, m)*2;
        else if(res==1) return (int)pow(3, m-1)*4;
        return (int)pow(3, m);
    }
};
// @lc code=end