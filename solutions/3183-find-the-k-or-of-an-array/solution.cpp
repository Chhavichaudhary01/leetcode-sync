class Solution {
public:
   int findKOr(vector<int>& nums, int k) {
    int ans = 0;

    for(int bit = 0; bit < 32; bit++){
        int count = 0;

        for(int x : nums){
            if(x & (1 << bit)){
                count++;
            }
        }

        if(count >= k){
            ans |= (1 << bit);
        }
    }

    return ans;
}
};
