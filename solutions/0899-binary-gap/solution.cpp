class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int pos = 0;
        int maxDis = 0;
        while(n>0){
            if(n& 1){
                if(last != -1){
                    maxDis = max(maxDis, pos - last);
                }
                last= pos;
            }
            pos++;
            n = n >> 1;
        }
        return maxDis;
        
    }
};
