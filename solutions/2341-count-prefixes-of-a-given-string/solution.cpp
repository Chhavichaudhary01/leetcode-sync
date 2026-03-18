class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;

        for(string word : words){
            if(s.substr(0, word.length()) == word){
                count++;
            }
        }

        return count;
    }
};
