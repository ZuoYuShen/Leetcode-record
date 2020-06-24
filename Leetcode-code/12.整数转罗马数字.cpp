/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int nums[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string c[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res;
        while(num>0){
            for(int i=12; i>=0; i--){
                if(num>=nums[i]){
                    res += c[i];
                    num -= nums[i];
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

