class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.resize(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;

        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }

        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int LIMIT = min(50000, (int)queries.size() * 3);

        set<int> obstacles = {0, LIMIT};

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        FenwickTree bit(LIMIT + 2);

        auto it = obstacles.begin();

        while (next(it) != obstacles.end()) {

            int left = *it;
            int right = *next(it);

            bit.update(right, right - left);

            ++it;
        }

        vector<bool> ans;

        for (int i = queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 1) {

                int x = queries[i][1];

                auto cur = obstacles.find(x);

                int prevPos = *prev(cur);
                int nextPos = *next(cur);

                bit.update(nextPos, nextPos - prevPos);

                obstacles.erase(cur);
            }
            else {

                int x = queries[i][1];
                int sz = queries[i][2];

                auto it = obstacles.upper_bound(x);

                int prevObstacle = *prev(it);

                bool possible =
                    (bit.query(prevObstacle) >= sz) ||
                    (x - prevObstacle >= sz);

                ans.push_back(possible);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
