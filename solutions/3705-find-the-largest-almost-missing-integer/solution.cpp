class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // count[x] = number of size-k subarrays containing x
        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            // Find distinct elements in current window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Each distinct element appears in this subarray once
            for (int x : st) {
                count[x]++;
            }
        }

        // Find largest integer appearing in exactly one subarray
        int ans = -1;

        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};
