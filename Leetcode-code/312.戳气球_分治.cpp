/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int findmax(int begin, int end, vector<int>& val, vector<vector<int>>& store) {
        if(begin >= end) return 0;
        if(store[begin][end]!=0) return store[begin][end];
        int max = 0;
        for(int i=begin+1; i<end; i++){
            int val_k = findmax(begin, i, val, store) + findmax(i, end, val, store) + val[begin]*val[i]*val[end];
            if(val_k > max) max = val_k;
        }
        store[begin][end] = max;
        return max;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> val;
        int n = nums.size();
        int res;
        val.resize(n+2);
        for(int i=1; i<=n; i++){
            val[i] = nums[i-1];
        }
        val[0] = 1;
        val[n+1] = 1;
        vector<vector<int>> store(n+2, vector<int>(n+2));
        res = findmax(0, n+1, val, store);
        return res;
    }
};
// @lc code=end