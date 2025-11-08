class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            // Push opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If closing bracket but stack empty -> invalid
                if(st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Check matching pairs
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // Stack must be empty for valid
        return st.empty();
    }
};

