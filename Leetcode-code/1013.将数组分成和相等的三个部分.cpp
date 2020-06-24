/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        int index1 = 0;
        int index2 = A.size()-1;
        int cur_sum_left = 0;
        int cur_sum_right = 0;
        for(int i=0; i<A.size(); i++) sum += A[i];
        while(index1<A.size()){
            cur_sum_left += A[index1];
            if(cur_sum_left*3 == sum) break;
            index1++;
        }
        if(cur_sum_left*3 != sum) return false;
        while(index2>index1+1){
            cur_sum_right += A[index2];
            if(cur_sum_right*3 == sum){
                return true;
                break;
            }
            index2--;
        }
        return false;
    }
};
// @lc code=end

