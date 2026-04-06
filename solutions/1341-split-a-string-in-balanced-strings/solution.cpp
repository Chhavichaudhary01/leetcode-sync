class Solution {
public:
    int balancedStringSplit(string s) {
        int count =0,balance =0;
        for(char ch:s){
            if(ch=='R') balance++;
            else balance--;
            if(balance ==0){
                count++;
            }
            
        }
        return count;
        
    }
};
