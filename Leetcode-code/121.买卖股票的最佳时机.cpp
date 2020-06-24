/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int Max_profit = 0;
        int min_val = prices[0];
        for(int i=1; i<prices.size(); i++){
            Max_profit = max(Max_profit, prices[i] - min_val);
            min_val = min(prices[i], min_val);
        }
        return max(0, Max_profit);
    }
};
// @lc code=end

