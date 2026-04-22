class Solution {
public:
    
    // function to count differences
    int diffCount(string &a, string &b) {
        int count = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) count++;
        }
        return count;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for(auto &q : queries) {
            for(auto &d : dictionary) {
                
                if(diffCount(q, d) <= 2) {
                    ans.push_back(q);
                    break; // ek match mil gaya, aage check nahi karna
                }
                
            }
        }
        
        return ans;
    }
};
