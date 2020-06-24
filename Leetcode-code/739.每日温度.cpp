/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> tempIndex;
        for(int i=0; i<n; i++){
            while(!tempIndex.empty() && T[i]>T[tempIndex.top()]){
                int prevdis = i - tempIndex.top();
                res[tempIndex.top()] = prevdis;
                tempIndex.pop();
            }
            tempIndex.push(i);
        }
        return res;
    }
};
// @lc code=end

