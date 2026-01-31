class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2; // peak can not lie at 0 & n-1 index
        while(st<=end){
            int mid = st+(end-st)/2;
            if(arr[mid -1]<arr[mid]&& arr[mid+1]<arr[mid]){
                return mid;
            }

            if(arr[mid]>arr[mid-1])//left increment
            {
                st = mid +1;// search in right side
            }else{// right increment
               end = mid -1; // search in left side

            }
        }
        return -1;
    }
};
