class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> digits, pos;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // Prefix sum of digits
        vector<long long> prefSum(m + 1, 0);

        // Prefix number modulo MOD
        vector<long long> prefNum(m + 1, 0);

        // Powers of 10
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long sum = prefSum[R + 1] - prefSum[L];

            long long x = (prefNum[R + 1]
                          - (prefNum[L] * pow10[len]) % MOD
                          + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};
