/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> Order;
        int num_of_ana=0;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++){
            string s_order = strs[i];
            sort(s_order.begin(), s_order.end());
            if(!Order.count(s_order)){
                Order[s_order] = num_of_ana;
                num_of_ana++;
                vector<string> cur;
                cur.push_back(strs[i]);
                res.push_back(cur);
            }
            else{
                res[Order[s_order]].push_back(strs[i]);
            }
        }
        return res;
    }
};
// @lc code=end

