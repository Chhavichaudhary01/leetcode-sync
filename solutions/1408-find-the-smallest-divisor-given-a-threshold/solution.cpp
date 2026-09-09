class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + mid - 1) / mid;
            }

            if (sum <= threshold) {
                // mid valid hai
                high = mid - 1;
            }
            else {
                // mid chhota hai, divisor badhana padega
                low = mid + 1;
            }
        }

        return low;
    }
};
