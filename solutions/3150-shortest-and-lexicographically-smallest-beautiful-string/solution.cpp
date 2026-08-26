class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        
        string ans = "";
        
        for (int right = 0; right < n; right++) {
            
            if (s[right] == '1')
                ones++;
            
            // Window has exactly k ones
            while (ones == k) {
                
                string curr = s.substr(left, right - left + 1);
                
                // First valid answer
                if (ans == "" || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
                
                // Remove left character
                if (s[left] == '1')
                    ones--;
                
                left++;
            }
        }
        
        return ans;
    }
};
