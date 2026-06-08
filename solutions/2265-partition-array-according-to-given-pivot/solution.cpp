class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>leftArr;
        vector<int>rightArr,equalArr;
        for(int i =0;i<n;i++){
            if(nums[i]<pivot){
                leftArr.push_back(nums[i]);

            }
            
            else if(nums[i]== pivot){
                equalArr.push_back(nums[i]);


            }

            else{
                rightArr.push_back(nums[i]);
            }

        }
        vector<int>ans;
        for(int x : leftArr) ans.push_back(x);
        for(int x: equalArr) ans.push_back(x);
        for(int x: rightArr) ans.push_back(x);
        return ans;
       

        
    }
};
