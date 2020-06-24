/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        if(arr.back()*arr.size()<=target) return arr.back();
        int cur_sum=0;
        int len = arr.size();
        for(int i=0; i<len; i++){
            if(arr[i]*(len-i)+cur_sum>=target){
                int change = (target-cur_sum)/(len-i);
                double change_precise = ((double)(target-cur_sum))/(len-i);
                if(change_precise - change > 0.5) change += 1;
                return change;
            }
            cur_sum += arr[i];
        }
        return arr[len-1];
    }
};
// @lc code=end

