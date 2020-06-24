/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int S_max = 0;
        int S_cur = 0;
        int left = 0;
        int right = height.size()-1;
        while(right>left){
            S_cur = (right-left)*min(height[left], height[right]);
            S_max = max(S_max, S_cur);
            height[left] < height[right] ? left++ : right--;
        }
        return S_max;
    }
};
// @lc code=end
