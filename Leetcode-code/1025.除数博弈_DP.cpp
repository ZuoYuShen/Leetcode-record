/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        if(N==1) return false;
        vector<bool> Alice(N+1, 0);
        Alice[2] = true;
        for(int i=2; i<N+1; i++){
            bool tmp = false;
            for(int x=1; x<i; x++){
                if(i%x==0 && Alice[i-x]==false) tmp = true;
            }
            Alice[i] = tmp;
        }
        return Alice[N];
    }
};
// @lc code=end