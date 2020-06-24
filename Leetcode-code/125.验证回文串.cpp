/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        bool flag_1=false;
        bool flag_2=false;
        while(i<=j){
            if((s[i] >='0' && s[i]<='9') || (s[i] >='a' && s[i]<='z') || (s[i] >='A' && s[i]<='Z')){
                flag_1 = true;
                if((s[i] >='A' && s[i]<='Z')) s[i] = tolower(s[i]);
            }
            if((s[j] >='0' && s[j]<='9') || (s[j] >='a' && s[j]<='z') || (s[j] >='A' && s[j]<='Z')){
                flag_2 = true;
                if((s[j] >='A' && s[j]<='Z')) s[j] = tolower(s[j]);
            }
            if(!flag_1 && flag_2) i++;
            if(flag_1 && !flag_2) j--;
            if(flag_1 && flag_2){
                if(s[i]!=s[j]) return false;
                i++;
                j--;
            }
            if(!flag_1 && !flag_2){
                i++;
                j--;
            }
            flag_1 = false;
            flag_2 = false;
        }
        return true;
    }
};
// @lc code=end

