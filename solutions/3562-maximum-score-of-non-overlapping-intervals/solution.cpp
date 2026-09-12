class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {l, r, weight, original_index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by l, then r, then weight, then original index
        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5, {0, {}})
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Skip current interval
                Node skip = dp[i + 1][k];

                // Take current interval
                Node take = dp[nxt[i]][k - 1];

                take.score += a[i][2];

                // Insert original index in sorted order
                auto it = lower_bound(
                    take.indices.begin(),
                    take.indices.end(),
                    (int)a[i][3]
                );

                take.indices.insert(it, (int)a[i][3]);

                if (better(take, skip)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].indices;
    }
};
