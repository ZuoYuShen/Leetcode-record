/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        int prev = 1;
        int cur = 2;
        int tmp;
        for(int i=3; i<=n; i++){
            tmp = cur + prev;
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};
// @lc code=end

