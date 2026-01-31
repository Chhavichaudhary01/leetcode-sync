class Solution {
public:
    bool isValid(vector<int>& nums, int m, int mid){
        int stu = 1, pages = 0;

        for(int x : nums){
            if(x > mid) return false;   // single element > mid → impossible

            if(pages + x <= mid){
                pages += x;
            } else {
                stu++;
                pages = x;
            }
        }
        return stu <= m;   // <= m hona chahiye
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();

        int sum = 0, mx = 0;
        for(int x : nums){
            sum += x;
            mx = max(mx, x);
        }

        int st = mx, end = sum, ans = sum;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isValid(nums, m, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};

