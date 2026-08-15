class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        // Whole array already has non-zero XOR
        if (xr != 0) {
            return n;
        }

        // Whole array XOR is 0, but we can remove
        // one non-zero element
        if (hasNonZero) {
            return n - 1;
        }

        // All elements are zero
        return 0;
    }
};
