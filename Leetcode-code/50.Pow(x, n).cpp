/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        int mul = 1;
        double res;
        if(x==1) return x;
        if(x==-1){
            n%2==1 ? res=x: res=-x;
            return res;
        }
        if((n==INT_MAX && x<1) || n==INT_MIN) return 0;
        if(n==0) return 1;
        if(n>0){
            res = x;
            while(2*mul <= n){
                res *= res;
                mul *= 2;
            }
        }
        else{
            res = 1/x;
            while(-2*mul >= n){
                res *= res;
                mul *= 2;
            }
        }
        int residual;
        n > 0 ? residual = n-mul : residual = n+mul;
        res *= myPow(x, residual);
        return res;
    }
};
// @lc code=end