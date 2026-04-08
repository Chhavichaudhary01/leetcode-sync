class Solution {
public:
    bool digitCount(string num) {
        vector<int> freq(10, 0);

        // Step 1: count frequency
        for(char ch : num){
            freq[ch - '0']++;
        }

        // Step 2: check condition
        for(int i = 0; i < num.size(); i++){
            int expected = num[i] - '0';

            if(freq[i] != expected){
                return false;
            }
        }

        return true;
    }
};
