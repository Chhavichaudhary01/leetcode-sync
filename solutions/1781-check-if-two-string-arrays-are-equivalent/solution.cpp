class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 , w2;
        for(string s1 : word1){
            w1 += s1;
        }
        for(string s2 :word2){
            w2 += s2;

        }
        if(w1 == w2){
            return true;
        }
        return false;
    }
};
