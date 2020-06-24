/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combine;
        int whole_length = nums1.size() + nums2.size();
        int i=0;
        int j=0;
        double res;
        while(i<=nums1.size() || j<=nums2.size()){
            if(whole_length%2==1 && combine.size()==(whole_length+1)/2){
                res = combine.back();
                break;
            }
            if(whole_length%2==0 && combine.size()==whole_length/2+1){
                double num1 = combine.back();
                double num2 = combine[combine.size()-2];
                res = (num1+num2)/2;
                break;
            }
            if(i==nums1.size()){
                combine.push_back(nums2[j++]);
                continue;
            }
            if(j==nums2.size()){
                combine.push_back(nums1[i++]);
                continue;
            }
            if(nums1[i] < nums2[j]){
                combine.push_back(nums1[i++]);
                continue;
            }
            if(nums1[i] >= nums2[j]){
                combine.push_back(nums2[j++]);
                continue;
            }
        }
        return res;
    }
};
// @lc code=end

