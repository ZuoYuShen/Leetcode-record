/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = 0;
        int k = 0;
        int index = 0;
        for(int i=0; i<n; i++){
            t = nums2[i];
            for(int j=index; j<m; j++){
                k = min(nums1[j], t);
                t = max(nums1[j], t);
                nums1[j] = k;
                if(t == nums2[i]){
                    index = j;
                }
            }
            nums1[m] = t;
            m = m+1;
        }
    }
};
// @lc code=end

