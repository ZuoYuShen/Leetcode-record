/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int rev_num = 0;
        int x_cp = x;
        while(x_cp!=0){
            int pop_num = x_cp % 10;
            x_cp = x_cp/10;
            if(rev_num > INT_MAX/10 || (rev_num==INT_MAX/10 && pop_num >7)) return false;
            rev_num = rev_num*10 + pop_num;
        }
        return rev_num == x;
    }
};
// @lc code=end

