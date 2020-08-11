/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<char>>& board) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j]!='O') return;
        board[i][j] = 'A';
        dfs(i-1, j, board);
        dfs(i, j-1, board);
        dfs(i+1, j, board);
        dfs(i, j+1, board);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m==0) return;
        n = board[0].size();
        for(int i=0; i<m; i++){
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
        for(int j=1; j<n-1; j++){
            dfs(0, j, board);
            dfs(m-1, j, board);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='A') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end