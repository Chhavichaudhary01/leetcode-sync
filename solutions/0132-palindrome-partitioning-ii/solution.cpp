class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // isPal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts needed for s[i...n-1]
        vector<int> dp(n + 1, 0);
        dp[n] = -1;   // Base case: no cut needed after the last character

        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;

            for (int j = i; j < n; j++) {
                if (isPal[i][j]) {
                    mini = min(mini, 1 + dp[j + 1]);
                }
            }

            dp[i] = mini;
        }

        return dp[0];
    }
};
