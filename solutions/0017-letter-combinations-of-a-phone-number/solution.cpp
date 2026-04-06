class Solution {
public:
    vector<string> ans;
    void helper(string &digits,int idx,string &current,vector<string> &map){
        if(idx == digits.size()){
            ans.push_back(current);
            return;

        }
        string letters = map[digits[idx]-'0'];
        for(char ch : letters){
            current.push_back(ch);
            helper(digits,idx+1,current,map);
            current.pop_back();


        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>map={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        string current = "";
        helper(digits, 0,current,map);
        return ans;
        
    }
};
