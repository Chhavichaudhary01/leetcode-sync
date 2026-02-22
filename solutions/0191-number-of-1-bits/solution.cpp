class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        while(n>0){
            if(n&1){ // to check the bit is 1 or 0 ---> n & 1 return 1
                count++;
            }
            n= n>>1; //last ki digit hatate jao
        }
        return count;
        
    }
};
