/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){ return a[0] < b[0]; });
        vector<vector<int>> res;
        int cur_min = intervals[0][0];
        int cur_max = intervals[0][1];
        for(int i=0; i+1<intervals.size(); i++){
            if(intervals[i+1][0] > cur_max){
                res.push_back({cur_min, cur_max});
                cur_min = intervals[i+1][0];
                cur_max = intervals[i+1][1];
            }
            else{
                cur_max = max(intervals[i+1][1], cur_max);
            }
        }
        res.push_back({cur_min, cur_max});
        return res;
    }
};
// @lc code=end

