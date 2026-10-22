
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), k = nums[0];
        bool a = true, d = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) a = false;
            if (nums[i] != (k - i + n) % n) d = false;
        }

        if (!a && !d) return -1;

        vector<int> dist(2 * n, -1);
        queue<int> q;

        int start = (a ? 0 : n) + k;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int s = q.front();
            q.pop();

            int t = s / n, x = s % n;
            if (s == 0) return dist[s];

            int u = t * n + (x + (t ? n - 1 : 1)) % n;
            int v = (1 - t) * n + (x + (t ? 1 : n - 1)) % n;

            for (int y : {u, v}) {
                if (dist[y] == -1) {
                    dist[y] = dist[s] + 1;
                    q.push(y);
                }
            }
        }

        return -1;
    }
};

