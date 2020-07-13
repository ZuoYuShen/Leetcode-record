/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集Ⅱ
 */

// @lc code=start
class Solution {
public:
    vector<int> interset(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> H;
        if(nums1.size() > nums2.size()){
            return interset(nums2, nums1);
        }
        for(int i=0; i<nums1.size(); i++){
            if(H.count(nums1[i])) H[nums1[i]]++;
            else H[nums1[i]] = 1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(H.count(nums2[i]) && H[nums2[i]]!=0){
                res.push_back(nums2[i]);
                H[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end