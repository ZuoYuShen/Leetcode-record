/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Res;
        sort(nums.begin(), nums.end());
        if(nums.size()<3) return Res;
        int L, R;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            L = i+1;
            R = nums.size()-1;
            while(L<R){
                int sum = nums[i]+nums[L]+nums[R];
                if(sum==0){
                    Res.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    while(L<R && nums[L]==nums[L+1]) L++;
                    while(L<R && nums[R]==nums[R-1]) R--;
                    L++;
                    R--;
                }
                if(sum>0) R--;
                if(sum<0) L++;
            }
        }
        return Res;
    }
};
// @lc code=end
