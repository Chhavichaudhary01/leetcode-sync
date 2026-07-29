class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s1, string &s2, string &s3) {

        // Base case
        if (i == s1.size() && j == s2.size())
            return true;

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        // Take current character from s1
        if (i < s1.size() && s1[i] == s3[i + j])
            ans = ans || solve(i + 1, j, s1, s2, s3);

        // Take current character from s2
        if (j < s2.size() && s2[j] == s3[i + j])
            ans = ans || solve(i, j + 1, s1, s2, s3);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        // Total length must match
        if (s1.size() + s2.size() != s3.size())
            return false;

        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return solve(0, 0, s1, s2, s3);
    }
};
