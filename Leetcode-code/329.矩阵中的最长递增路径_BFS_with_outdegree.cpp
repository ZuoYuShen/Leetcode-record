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

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        rows = matrix.size();
        columns = matrix[0].size();
        vector<vector<int>> outdegree(rows, vector<int>(columns));
        queue<pair<int, int>> index;
        int max_length = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                for(int k=0; k<4; k++){
                    int newRow = i + dirs[k][0];
                    int newCol = j + dirs[k][1];
                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<columns && matrix[newRow][newCol] > matrix[i][j]){
                        outdegree[i][j] += 1;
                    }
                }
                if(outdegree[i][j]==0) index.push({i,j});
            }
        }
        while(!index.empty()){
            max_length++;
            int n = index.size();
            for(int i=0; i<n; i++){
                auto tmp = index.front();
                int cur_row = tmp.first;
                int cur_col = tmp.second;
                index.pop();
                for(int k=0; k<4; k++){
                    int newRow = cur_row + dirs[k][0];
                    int newCol = cur_col + dirs[k][1];
                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<columns && matrix[newRow][newCol] < matrix[cur_row][cur_col]){
                        outdegree[newRow][newCol] -= 1;
                        if(outdegree[newRow][newCol]==0) index.push({newRow, newCol});
                    }
                }
            }
        }
        return max_length;
    }
};
// @lc code=end