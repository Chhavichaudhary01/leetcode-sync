class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        // build mask
        for(char c : allowed){
            mask |= (1 << (c - 'a'));
        }

        int count = 0;

        for(string word : words){
            bool ok = true;

            for(char c : word){
                if((mask & (1 << (c - 'a'))) == 0){
                    ok = false;
                    break;
                }
            }

            if(ok) count++;
        }

        return count;
    }
};
