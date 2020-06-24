/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    long add(long num, long divisor){
        int count = 1;
        long acc_count = divisor;
        if(num < divisor) return 0;
        while((acc_count + acc_count) <= num){
            acc_count = acc_count + acc_count;
            count  = count + count;
        }
        return count + add(num-acc_count, divisor);
    }

    int divide(int dividend, int divisor) {
        long res;
        if(divisor==-1){
            if(dividend==INT_MIN) return INT_MAX;
            return -dividend;
        }
        if(divisor==1) return dividend;
        if(dividend==0) return 0;
        long a = dividend;
        long b = divisor;
        int negative = 0;
        if((a>0&&b<0) || (a<0&&b>0)) negative = 1;
        a = a>0 ? a : -a;
        b = b>0 ? b : -b;
        res = add(a,b);
        return negative==0 ? res : -res;
    }
};
// @lc code=end

