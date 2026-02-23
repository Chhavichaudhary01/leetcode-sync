class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26,0);
        for(char ch :s){
            freq[ch - 'a']++;
        }
        int count =0;
        for(int i =0;i<26;i++){
            if(freq[i]!=0){
                count = freq[i];
                break;
            }
        }
        //compare all frequencies
        for(int i =0;i<26;i++){
            if(freq[i]!=0 && freq[i]!=count){
                return false;
            }
        }
        return true;
        
    }
};
