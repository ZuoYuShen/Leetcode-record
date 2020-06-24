/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int nums[7] = {1,5,10,50,100,500,1000};
        char c[7] = {'I','V','X','L','C','D','M'};
        int s_len = s.size();
        int i=0;
        int res=0;
        while(i<s_len){
            if(s[i]=='C'&& i+1<s_len && s[i+1]=='M'){
                res += 900;
                i += 2;
            }
            if(s[i]=='C'&& i+1<s_len && s[i+1]=='D'){
                res += 400;
                i += 2;
            }
            if(s[i]=='X'&& i+1<s_len && s[i+1]=='C'){
                res += 90;
                i += 2;
            }
            if(s[i]=='X'&& i+1<s_len && s[i+1]=='L'){
                res += 40;
                i += 2;
            }
            if(s[i]=='I'&& i+1<s_len && s[i+1]=='X'){
                res += 9;
                i += 2;
            }
            if(s[i]=='I'&& i+1<s_len && s[i+1]=='V'){
                res += 4;
                i += 2;
            }
            for(int j=0; j<7; j++){
                if(s[i]==c[j]){
                    res += nums[j];
                    i += 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end

