/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int rev_num = 0;
        while(x!=0){
            int pop_num = x % 10;
            x = x/10;
            if(rev_num > INT_MAX/10 || (rev_num==INT_MAX/10 && pop_num > 7)) return 0;
            if(rev_num < INT_MIN/10 || (rev_num==INT_MIN/10 && pop_num < -8)) return 0;
            rev_num = rev_num*10 + pop_num;
        }
        return rev_num;
    }
};
// @lc code=end

