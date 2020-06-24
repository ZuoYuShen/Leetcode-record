/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int vl[26] = {0};
        for(char c : licensePlate){
            if(c>='a' && c<='z') vl[c-'a']++;
            else if(c>='A' && c<='Z') vl[c-'A']++;
        }
        string res;
        int res_length = INT_MAX;
        for(string word : words){
            if(word.size()<res_length){
                int vw[26] = {0};
                for(char c : word){
                    if(c>='a' && c<='z') vw[c-'a']++;
                    else if (c>='A' && c<='Z') vw[c-'A']++;
                }
                bool flag = true;
                for(int i=0; i<26; i++){
                    if(vl[i]>vw[i]) flag = false;
                }
                if(flag){
                    res_length = word.size();
                    res = word;
                }
            }
        }
        return res;
    }
};
// @lc code=end

