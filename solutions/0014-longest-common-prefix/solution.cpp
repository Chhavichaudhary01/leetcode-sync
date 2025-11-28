class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0]; // assume entire first string is prefix

        for (int i = 1; i < strs.size(); i++) {
            // reduce prefix until it matches the beginning of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back(); // remove last character
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

