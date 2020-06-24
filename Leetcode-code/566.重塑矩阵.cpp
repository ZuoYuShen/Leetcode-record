/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(!nums.size()) return nums;
        int rows_ori = nums.size();
        int cols_ori = nums[0].size();
        if(rows_ori*cols_ori != r*c) return nums;
        vector<vector<int>> result(r, vector<int>(c));
        for(int i=0; i<r*c; i++){
            result[i/c][i%c] = nums[i/cols_ori][i%cols_ori];
        }
        return result;
    }
};
// @lc code=end

