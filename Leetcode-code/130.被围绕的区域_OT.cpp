/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> near = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool getout(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
        int m = board.size(), n = board[0].size();
        if(i==0 || j==0 || i==m-1 || j==n-1) return true;
        bool connect = false;
        for(int k=0; k<4; k++){
            int new_row = i + near[k][0], new_col = j + near[k][1];
            if(board[new_row][new_col]=='X') continue;
            if(visited[new_row][new_col]==1) continue;
            visited[new_row][new_col] = 1;
            connect = connect || getout(new_row, new_col, board, visited);
            visited[new_row][new_col] = 0;
        }
        return connect;
    }

    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !getout(i, j, board, visited)) board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end