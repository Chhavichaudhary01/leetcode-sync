class Solution {
public:
   bool isValid(vector<int>& nums, int mid,int n,int m){
    int ball=1, lastPos = nums[0];
    for(int i =1;i<n;i++){
        if(nums[i]-lastPos>=mid){
            ball++;
            lastPos=nums[i];
        }
        if(ball==m) return true;
    }
    return false;

   }


    int maxDistance(vector<int>& nums, int m) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int st =1, end = nums[n-1]-nums[0],ans =-1;
        while(st<=end){
            int mid = st+ (end - st)/2;
            if(isValid(nums,mid,n,m)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;

        
    }
};
