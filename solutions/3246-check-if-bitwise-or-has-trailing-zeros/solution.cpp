class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int result = nums[i]|nums[j];
                if((result & 1) == 0){
                    return true;
                }
               
            }
        }
        return false;
        
    }
};
