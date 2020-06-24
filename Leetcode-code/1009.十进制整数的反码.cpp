/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int N) {
        int pow2_N = 2;
        while(true){
            if(pow2_N-1>=N) return pow2_N-1-N;
            pow2_N *= 2;
        }
        return 0;
    }
};
// @lc code=end

