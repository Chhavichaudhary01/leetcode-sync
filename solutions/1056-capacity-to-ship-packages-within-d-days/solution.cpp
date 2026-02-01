class Solution {
public:
    bool isValid(vector<int>&nums,int  mid,int n,int m){

    int d =1, w =0;
    for(int i =0;i<n;i++){
        if(w+nums[i]<=mid){
            w+=nums[i];
        }else{
            d++;
            w=nums[i];
        }

    }
    return d<=m? true:false;
}

    int shipWithinDays(vector<int>& nums, int m) {
        int maxVal = INT_MIN,sum =0;
        int n = nums.size();
        for (int i =0;i<n;i++){
            maxVal = max(maxVal,nums[i]);
            sum+=nums[i];
        }
        int st = maxVal,end = sum,ans = -1;
        while(st<=end){
            int mid = st+ (end - st)/2;
            if(isValid(nums,mid,n,m)){
                ans = mid;

                end = mid-1;
            }else{
                st=mid+1;
            }

        }
        return ans;
        
    }
};
