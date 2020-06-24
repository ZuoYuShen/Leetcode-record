/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()==1) return true;
        if(bits[bits.size()-2]==0) return true;
        int i = 0;
        while(i<bits.size()-1){
            //if(bits[i]==0) i = i+1;
            //if(bits[i]==1) i = i+2;
            i += bits[i] + 1;
        }
        return i==bits.size()-1;
    }
};
// @lc code=end

