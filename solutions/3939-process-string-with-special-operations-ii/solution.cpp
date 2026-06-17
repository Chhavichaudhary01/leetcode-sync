class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        const long long LIM = 1e15 + 5;

        for (int i = 0; i < n; i++) {
            long long cur = len[i];

            if (s[i] >= 'a' && s[i] <= 'z') {
                len[i + 1] = min(LIM, cur + 1);
            }
            else if (s[i] == '*') {
                len[i + 1] = max(0LL, cur - 1);
            }
            else if (s[i] == '#') {
                len[i + 1] = min(LIM, cur * 2);
            }
            else { // %
                len[i + 1] = cur;
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {

            long long before = len[i];
            long long after = len[i + 1];

            if (s[i] >= 'a' && s[i] <= 'z') {

                if (k == before)
                    return s[i];

            }
            else if (s[i] == '*') {

                // length increased by 1 in reverse
                continue;

            }
            else if (s[i] == '#') {

                k %= before;

            }
            else { // %

                k = after - 1 - k;

            }
        }

        return '.';
    }
};
