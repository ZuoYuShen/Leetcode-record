/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool found = false;
        for(int i=s.size(); i>=0; i--){
            if(!found && s[i]==' ') continue;
            if(found && s[i]==' ') break;
            if(s[i] != ' ') found=true;
            len += 1;
        }
        return len;
    }
};
// @lc code=end