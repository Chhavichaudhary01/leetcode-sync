class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth =0;
        for(char c : s){
            if(c == '(' ){
                if(depth>0){
                    ans+=c;   //not outermost
                }
                depth++;
            }else{
                if(c == ')' ){
                    depth--;
                    if(depth>0){
                        ans +=c;
                    }
                }
            }

        }
        return ans;
        


    
    }
};
