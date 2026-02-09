class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        long long total = 0; // use long long to avoid overflow

        for(int i = 0; i < n; i++){
            vector<int> freq(26,0);
            for(int j = i; j < n; j++){
                freq[s[j]-'a']++;
                int mx = 0, mn = INT_MAX;
                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        mx = max(mx,freq[k]);
                        mn = min(mn,freq[k]);
                    }
                }
                total += (long long)(mx - mn);
            }
        }

        return total;
    }
};

