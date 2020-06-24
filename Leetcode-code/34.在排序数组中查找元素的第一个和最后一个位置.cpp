/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int bin_search(int L, int R, int target, vector<int>& nums, bool findstart){
        int Index;
        findstart ? Index=INT_MAX : Index=INT_MIN;
        while(L<=R){
            if(findstart){
                if(nums[L]==target){
                    Index = min(Index, L);
                    break;
                }
            }
            else{
                if(nums[R]==target){
                    Index = max(Index, R);
                    break;
                }
            }
            int mid = (L+R)/2;
            if(nums[mid]>target) R = mid-1;
            else if(nums[mid]<target) L = mid+1;
            else if(nums[mid]==target){
                if(findstart){
                    Index = min(Index, mid);
                    R = mid-1;
                }
                else{
                    Index = max(Index, mid);
                    L = mid+1;
                }
            }
        }
        return Index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int startIndex = INT_MAX;
        int endIndex = INT_MIN;
        if(nums.size()==0) return {-1, -1};
        if(nums.size()==1&&nums[0]==target) return {0, 0};
        if(nums[0]>target || nums.back()<target) return {-1, -1};
        vector<int> res;
        int L = 0;
        int R = nums.size()-1;
        bool findstart = true;
        startIndex = bin_search(L, R, target, nums, findstart);
        if(startIndex==INT_MAX) return {-1,-1};
        endIndex = bin_search(L, R, target, nums, !findstart);
        return {startIndex, endIndex};
    }
};
// @lc code=end

