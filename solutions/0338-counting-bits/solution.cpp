class Solution {
public:
int countOnes(int x){
        int count = 0;
        
        while(x > 0){
            if(x & 1){
                count++;
            }
            x = x >> 1;
        }
        
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i =0;i<=n;i++){
            ans.push_back(countOnes(i));

        }
        return ans;
    }
};
