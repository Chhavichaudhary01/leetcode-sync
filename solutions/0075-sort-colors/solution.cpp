// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int count0 =0,count1=0,count2=0;
//         for(int i=0;i<n;i++){ // count 0 ,1,2 in vector nums
//             if(nums[i]==0){
//                 count0++;

//             }else if(nums[i]==1){
//                 count1++;

//             }else{
//                 count2++;
//             }
        
//         }
//         int idx =0;
//         for(int i =0;i<count0;i++){ //now overwrite 0,1,2 in vector
//             nums[idx++]=0;
//         }
//         for(int i =0;i<count1;i++){
//             nums[idx++]=1;
//         }
//         for(int i =0;i<count2;i++){
//             nums[idx++]=2;
//         }

        
//     }
// };



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid =0, low = 0,high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        
        
    }
};


