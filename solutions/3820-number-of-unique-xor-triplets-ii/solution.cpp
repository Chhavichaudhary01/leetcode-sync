class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<int>> dp(4, vector<int>(MAXX, 0));
        dp[0][0] = 1;

        for (int num : nums) {
            for (int take = 2; take >= 0; take--) {
                for (int x = 0; x < MAXX; x++) {
                    if (dp[take][x]) {
                        dp[take + 1][x ^ num] = 1;
                    }
                }
            }
        }

        vector<int> vis(MAXX, 0);

        for (int x = 0; x < MAXX; x++) {
            if (dp[1][x]) vis[x] = 1;
            if (dp[3][x]) vis[x] = 1;
        }

        return accumulate(vis.begin(), vis.end(), 0);
    }
};
