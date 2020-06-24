/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<int>> Hash_map_row;
        unordered_map<char, vector<int>> Hash_map_col;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if(c=='.') continue;
                else{
                    if(!Hash_map_row.count(c)){
                        Hash_map_row[c].push_back(i);
                        Hash_map_col[c].push_back(j);
                    }
                    else{
                        for(int m=0; m<Hash_map_row[c].size(); m++){
                            if(i==Hash_map_row[c][m] || j==Hash_map_col[c][m]) return false;
                            else if((abs(i-Hash_map_row[c][m])<=2)&&(abs(j-Hash_map_col[c][m])<=2)){
                                if((i/3==Hash_map_row[c][m]/3)&&(j/3==Hash_map_col[c][m]/3)) return false;
                            }
                        }
                        Hash_map_row[c].push_back(i);
                        Hash_map_col[c].push_back(j);
                    }
                } 
            }
        }
        return true;
    }
};
// @lc code=end

