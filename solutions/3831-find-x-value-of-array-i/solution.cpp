class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);


            for (int r = 0; r < k; r++) {
                int newR = (1LL * r * (num % k)) % k;
                curr[newR] += dp[r];
            }


            curr[num % k]++;

            dp = curr;

            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};
