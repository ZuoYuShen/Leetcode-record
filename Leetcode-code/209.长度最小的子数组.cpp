/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums){
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0]>=s;
        int L = 0;
        int R = 0;
        int cur_sum = 0;
        int res = INT_MAX;
        while(R<=nums.size()){
            if(cur_sum < s){
                if(R < nums.size()) cur_sum += nums[R++];
                else break;
            }
            else{
                res = min(res, R-L);
                cur_sum -= nums[L++];
            }
        }
        if(L==0) return 0;
        return res;
    }
};
// @lc code=end