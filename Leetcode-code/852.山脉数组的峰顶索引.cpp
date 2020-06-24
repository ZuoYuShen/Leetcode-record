/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max_value = 0;
        int max_index = 0;
        for(int i=0; i<A.size(); i++){
            if(A[i]>max_value){
                max_value = A[i];
                max_index = i;
            }
        }
        return max_index;
    }
};
// @lc code=end

