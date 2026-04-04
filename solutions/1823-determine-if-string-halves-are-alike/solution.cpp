class Solution {
public:
    bool isVowel(char c){
        string v = "aeiouAEIOU";
        return v.find(c) != string::npos;
    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int count1 = 0, count2 = 0;

        // first half
        for(int i = 0; i < n/2; i++){
            if(isVowel(s[i])) count1++;
        }

        // second half
        for(int i = n/2; i < n; i++){
            if(isVowel(s[i])) count2++;
        }

        return count1 == count2;
    }
};
