/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int L,R;
        int cloest = INT_MAX;
        int cur_dis, res;
        for(int i=0; i<nums.size(); i++){
            L = i+1;
            R = nums.size()-1;
            while(L<R){
                int sum = nums[i]+nums[L]+nums[R];
                if(sum==target) return sum;
                else{
                    cur_dis = target - sum;
                    cur_dis = cur_dis>0 ? cur_dis : -cur_dis;
                    if(cur_dis < cloest){
                        res = sum;
                        cloest = cur_dis;
                    }
                }
                if(sum > target) R--;
                if(sum < target) L++;
            }
        }
        return res;
    }
};
// @lc code=end

