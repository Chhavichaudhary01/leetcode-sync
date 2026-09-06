class Solution {
public:
    bool validPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        
        while(st < end) {
            if(s[st] != s[end]) {
                
                // Delete left character
                int i = st + 1;
                int j = end;
                bool left = true;
                
                while(i < j) {
                    if(s[i] != s[j]) {
                        left = false;
                        break;
                    }
                    i++;
                    j--;
                }
                
                if(left)
                    return true;
                
                // Delete right character
                i = st;
                j = end - 1;
                
                while(i < j) {
                    if(s[i] != s[j])
                        return false;
                    i++;
                    j--;
                }
                
                return true;
            }
            
            st++;
            end--;
        }
        
        return true;
    }
};
