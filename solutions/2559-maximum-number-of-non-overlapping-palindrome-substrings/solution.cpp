class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i][j] = s[i...j] palindrome hai ya nahi
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        // best[i] = first i characters se maximum palindromes
        vector<int> best(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Current character ko skip kar do
            best[i] = best[i - 1];

            for (int j = 0; j < i; j++) {
                int len = i - j;

                if (len >= k && dp[j][i - 1]) {
                    best[i] = max(best[i], best[j] + 1);
                }
            }
        }

        return best[n];
    }
};
