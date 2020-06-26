/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 全排列 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(!matrix.size()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int L = 0;
        int R = m*n-1;
        if(L==R) return matrix[m-1][n-1]==target;
        while(L<R){
            if(matrix[L/n][L%n]==target || matrix[R/n][R%n]==target) return true;
            int mid = (L+R)/2;
            if(matrix[mid/n][mid%n]<target) L = mid+1;
            else if(matrix[mid/n][mid%n]>target) R = mid;
            else if(matrix[mid/n][mid%n]==target) return true;
        }
        return false;
    }
};
// @lc code=end