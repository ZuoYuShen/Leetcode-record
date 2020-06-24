/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int L = 0;
        int R = nums.size()-1;
        while(L<=R){
            if((target<nums[L]&&target>nums[R])) return -1;
            if(target==nums[L]) return L;
            if(target==nums[R]) return R;
            int mid = (L+R)/2;
            if(target==nums[mid]) return mid;
            if(target > nums[L]){
                if((target>nums[mid] && nums[mid]>nums[L])) L = mid+1;
                else R = mid-1;
            }
            else if(target < nums[R]){
                if(target<nums[mid] && nums[mid]<nums[L]) R = mid-1;
                else L = mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

