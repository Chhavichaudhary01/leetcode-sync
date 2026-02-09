class Solution {
public:
    void expand(string&s, int left,int right,int &start,int&maxLen){
        while(left>=0 && right <s.size()&& s[left]==s[right]){
            int len = right -left+1;
            if(len>maxLen){
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
       int n = s.size();
       if(n==0) return "";
       int start =0,maxLen=1;
       for(int i =0;i<n;i++){
        expand(s,i,i,start,maxLen);  //odd

        expand(s,i,i+1,start,maxLen);//even

       }
       return s.substr(start,maxLen);
        
      
        
    }
};
