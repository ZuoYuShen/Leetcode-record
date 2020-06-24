/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int word[26] = {0};
        vector<string> res;
        for(char c : A[0]){
            word[c-'a']++;
        }
        for(string s : A){
            int cur_word[26] = {0};
            for(char c : s){
                cur_word[c-'a']++;
            }
            for(int i=0; i<26; i++){
                word[i] = min(word[i], cur_word[i]);
            }
        }
        string str;
        for(int i=0; i<26; i++){
            if(word[i]>0){
                for(int t=0; t<word[i]; t++){
                    str.clear();
                    str.push_back((char)('a'+i));
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};
// @lc code=end

