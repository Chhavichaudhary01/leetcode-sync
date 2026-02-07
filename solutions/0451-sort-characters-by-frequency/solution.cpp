class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        // step 1: count frequency
        for(char c : s) {
            freq[c]++;
        }

        // step 2: move to vector for sorting
        vector<pair<char,int>> v(freq.begin(), freq.end());

        // step 3: sort by frequency descending
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // step 4: build answer
        string ans = "";
        for(auto &p : v) {
            ans.append(p.second, p.first); // repeat char
        }

        return ans;
    }
};

