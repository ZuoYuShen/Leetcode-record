/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    map<char, string> M = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, 
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

    vector<string> res;
    string current;

    void DFS(int index, string digits){
        if(index==digits.size()){
            res.push_back(current);
            //current.clear();
            return;
        }
        for(int i=0; i < M[digits[index]].size(); i++){
            current.push_back(M[digits[index]][i]);
            DFS(index+1, digits);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        DFS(0, digits);
        return res;
    }
};
// @lc code=end

