class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto push = [&](auto&& self, int node, int l, int r) -> void {
            if (lazy[node] == 0) return;

            long long x = lazy[node];
            long long len = r - l + 1;

            sq[node] = (sq[node] + 2 * x % MOD * sum[node] % MOD
                        + len * x % MOD * x % MOD) % MOD;

            sum[node] = (sum[node] + len * x) % MOD;

            if (l != r) {
                lazy[node * 2] = (lazy[node * 2] + x) % MOD;
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + x) % MOD;
            }

            lazy[node] = 0;
        };

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            push(push, node, l, r);

            if (r < ql || l > qr) return;

            if (ql <= l && r <= qr) {
                lazy[node] = (lazy[node] + 1) % MOD;
                push(push, node, l, r);
                return;
            }

            int mid = (l + r) / 2;

            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(update, 1, 0, n - 1, prev + 1, i);

            ans = (ans + sq[1]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
