class Solution {
public:
    void helper(string num, int target, int index, 
                long currValue, long lastValue, 
                string path, vector<string> &ans) {
        
        if(index == num.size()) {
            if(currValue == target) {
                ans.push_back(path);
            }
            return;
        }

        for(int i = index; i < num.size(); i++) {
            
            // ❌ leading zero case
            if(i > index && num[index] == '0') break;

            string s = num.substr(index, i - index + 1);
            long val = stol(s);

            if(index == 0) {
                // first number → no operator
                helper(num, target, i+1, val, val, s, ans);
            } else {
                // +
                helper(num, target, i+1, currValue + val, val, path + "+" + s, ans);

                // -
                helper(num, target, i+1, currValue - val, -val, path + "-" + s, ans);

                // *
                helper(num, target, i+1, 
                       currValue - lastValue + (lastValue * val), 
                       lastValue * val, 
                       path + "*" + s, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};
