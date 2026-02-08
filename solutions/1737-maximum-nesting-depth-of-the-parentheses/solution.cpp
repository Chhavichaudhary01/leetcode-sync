class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int maxdepth =0;
        for(char c:s){
            if (c=='('){
                count++;
                maxdepth = max(count,maxdepth);
            }
            else if(c==')'){
            count--;
            }

                
            
        }
        return maxdepth;
    }
};
