class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        
        int total = 1 << k; // 2^k
        
        for(int i = 0; i + k <= s.length(); i++) {
            string sub = s.substr(i, k);
            st.insert(sub);
            
            if(st.size() == total) return true;
        }
        
        return false;
    }
};
