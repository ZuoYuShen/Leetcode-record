/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第k小的元素
 */

// @lc code=start
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n){
        int i = n-1;
        int j = 0;
        int num = 0;
        while(i>=0 && j<n){
            if(matrix[i][j] <= mid){
                num += (i+1);
                j++;
            }
            else i--;
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left < right){
            int mid = left + ((right-left) >> 1);
            if(check(matrix, mid, k, n)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
