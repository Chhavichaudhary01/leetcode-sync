class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> words;
        string temp = "";

        // split string by space
        for(char c : s){
            if(c == ' '){
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp);

        // length mismatch
        if(p.length() != words.size()) return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i = 0; i < p.length(); i++){
            char ch = p[i];
            string word = words[i];

            if(mp1.count(ch) && mp1[ch] != word) return false;
            if(mp2.count(word) && mp2[word] != ch) return false;

            mp1[ch] = word;
            mp2[word] = ch;
        }

        return true;
    }
};
