class Solution {
public:
    
    set<string> combine(set<string> a, set<string> b) {
        set<string> ans;
        
        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }
        
        return ans;
    }
    
    set<string> solve(string &s, int &i) {
        
        set<string> ans;
        set<string> cur;
        
        cur.insert("");
        
        while (i < s.size() && s[i] != '}') {
            
            // Union
            if (s[i] == ',') {
                
                for (string x : cur)
                    ans.insert(x);
                
                cur.clear();
                cur.insert("");
                
                i++;
            }
            
            // Braces
            else if (s[i] == '{') {
                
                i++;  // skip '{'
                
                set<string> inside = solve(s, i);
                
                i++;  // skip '}'
                
                cur = combine(cur, inside);
            }
            
            // Letter
            else {
                
                set<string> letter;
                letter.insert(string(1, s[i]));
                
                cur = combine(cur, letter);
                
                i++;
            }
        }
        
        // Add last part
        for (string x : cur)
            ans.insert(x);
        
        return ans;
    }
    
    vector<string> braceExpansionII(string expression) {
        
        int i = 0;
        
        set<string> result = solve(expression, i);
        
        vector<string> ans(result.begin(), result.end());
        
        return ans;
    }
};
