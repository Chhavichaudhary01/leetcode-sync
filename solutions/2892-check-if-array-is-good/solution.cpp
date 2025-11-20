class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // Condition 1: length must be n + 1
        if (nums.size() != n + 1) return false;

        vector<int> freq(n + 1, 0);

        // Count frequencies
        for (int x : nums) {
            if (x > n) return false;  // invalid number
            freq[x]++;
        }

        // Check numbers 1..n-1 appear once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1) return false;
        }

        // Check number n appears twice
        return freq[n] == 2;
    }
};

