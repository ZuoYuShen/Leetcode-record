/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第k小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flatten;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                flatten.push_back(matrix[i][j]);
            }
        }
        sort(flatten.begin(), flatten.end());
        return flatten[k-1];
    }
};
// @lc code=end
