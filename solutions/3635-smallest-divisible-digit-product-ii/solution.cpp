class Solution {
public:

    int a[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };

    int dp[47][30][21][17];

    int solve(int x, int y, int z, int w) {
        if (x == 0 && y == 0 && z == 0 && w == 0)
            return 0;

        int &res = dp[x][y][z][w];

        if (res != -1)
            return res;

        res = 1e9;

        for (int d = 1; d <= 9; d++) {
            int nx = max(0, x - a[d][0]);
            int ny = max(0, y - a[d][1]);
            int nz = max(0, z - a[d][2]);
            int nw = max(0, w - a[d][3]);

            res = min(res, 1 + solve(nx, ny, nz, nw));
        }

        return res;
    }

    string makeString(vector<int> need, int len) {
        string ans;

        for (int i = 0; i < len; i++) {

            for (int d = 1; d <= 9; d++) {

                vector<int> nxt(4);

                for (int j = 0; j < 4; j++)
                    nxt[j] = max(0, need[j] - a[d][j]);

                if (solve(nxt[0], nxt[1], nxt[2], nxt[3])
                    <= len - i - 1) {

                    ans += char('0' + d);
                    need = nxt;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        vector<int> need(4);
        int p[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % p[i] == 0) {
                need[i]++;
                t /= p[i];
            }
        }

        if (t != 1)
            return "-1";

        memset(dp, -1, sizeof(dp));

        int n = num.size();

        vector<array<int,4>> pref(n + 1);
        vector<bool> good(n + 1, true);

        pref[0] = {0, 0, 0, 0};

        for (int i = 0; i < n; i++) {

            int d = num[i] - '0';

            pref[i + 1] = pref[i];

            for (int j = 0; j < 4; j++)
                pref[i + 1][j] += a[d][j];

            if (d == 0)
                good[i + 1] = false;
            else
                good[i + 1] = good[i];
        }

        bool ok = good[n];

        if (ok) {
            for (int j = 0; j < 4; j++) {
                if (pref[n][j] < need[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        for (int i = n - 1; i >= 0; i--) {

            if (!good[i])
                continue;

            int cur = num[i] - '0';

            for (int d = cur + 1; d <= 9; d++) {

                vector<int> req(4);

                for (int j = 0; j < 4; j++) {
                    int have = pref[i][j] + a[d][j];
                    req[j] = max(0, need[j] - have);
                }

                int len = n - i - 1;

                if (solve(req[0], req[1], req[2], req[3]) <= len) {

                    return num.substr(0, i) +
                           char('0' + d) +
                           makeString(req, len);
                }
            }
        }

        int minLen = solve(
            need[0],
            need[1],
            need[2],
            need[3]
        );

        int len = max(n + 1, minLen);

        string ans = makeString(need, len);

        return ans.empty() ? "-1" : ans;
    }
};
