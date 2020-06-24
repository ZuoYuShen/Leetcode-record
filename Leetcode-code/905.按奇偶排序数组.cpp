/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size()==1) return A;
        //vector<int> res(A.size(), 0);
        int start = 0;
        int end = A.size()-1;
        while(start<=end){
            if(A[start]%2==1 && A[end]%2==0){
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
            }
            if(A[start]%2==0) start++;
            if(A[end]%2==1) end--;
        }
        return A;
    }
};
// @lc code=end

