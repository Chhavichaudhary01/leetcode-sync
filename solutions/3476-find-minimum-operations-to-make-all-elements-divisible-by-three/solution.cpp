class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            nums[i]++;
            if(nums[i]%3==0){
                count ++;
            }
            else{
                nums[i]=nums[i]-2;
                if(nums[i]%3==0){
                    count++;
                }
            }
        }
        return count;
    }
};
