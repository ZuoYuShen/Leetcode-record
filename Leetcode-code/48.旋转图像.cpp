/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix.size();
        int row = 0;
        
        while(start+1 < end){
            for(int i=start; i<end-1; i++){
                int temp = matrix[row][i];
                matrix[row][i] = matrix[end-i-1+start][row];
                matrix[end-i-1+start][row] = matrix[end-row-1+start][end-i-1+start];
                matrix[end-row-1+start][end-i-1+start] = matrix[i][end-row-1+start];
                matrix[i][end-row-1+start] = temp;
            }
            start++;
            end--;
            row++;
        }
    }
};
// @lc code=end

