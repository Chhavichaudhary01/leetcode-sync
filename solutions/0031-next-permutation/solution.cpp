class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find pivot
        int piv =-1,n = nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                piv = i;
                break;
            }
        }
        if(piv ==-1){
            reverse(nums.begin(),nums.end());
            return;
            
        }
        // find rightmost element greater than pivot
        for(int i =n-1;i>piv;i--){
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;

            }
        }
        // reverse (piv+1 to n-1) **2 -pointer's approach
        int i = piv +1;
        int j = n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};
