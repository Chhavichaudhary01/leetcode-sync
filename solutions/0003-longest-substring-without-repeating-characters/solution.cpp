class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string st="";
        int left =0,maxLen=0;
        for(int right = 0; right<s.length();right++){
            
            while(st.find(s[right]) != string::npos){
                st.erase(0,1);
                left++;
            }
            st+= s[right];
            maxLen = max(maxLen, (int)st.length());

        }
        return maxLen;
        
    }
};
