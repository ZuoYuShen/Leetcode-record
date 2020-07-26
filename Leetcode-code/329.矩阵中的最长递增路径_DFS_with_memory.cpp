/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int rows, columns;

    int dfs(int row, int col, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if(memo[row][col]!=0) return memo[row][col];
        memo[row][col] += 1;
        for(int i=0; i<4; i++){
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];
            if(newRow>=0 && newRow<rows && newCol>=0 && newCol<columns && matrix[newRow][newCol]>martix[row][col]){
                memo[row][col] = max(memo[row][col], dfs(newRow, newCol, memo, matrix) + 1);
            }
        }
        return memo[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        rows = matrix.size();
        columns = matrix[0].size();
        vector<vector<int>> memo(rows, vector<int>(columns));
        int max_length = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                max_length = max(max_length, dfs(i, j, memo, matrix));
            }
        }
        return max_length;
    }
};
// @lc code=end