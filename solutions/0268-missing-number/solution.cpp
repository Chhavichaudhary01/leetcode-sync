class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            count++;
            if(nums[i]!= i ){
                return i;
            }
        }
        return count;
    }    

        
        
};
