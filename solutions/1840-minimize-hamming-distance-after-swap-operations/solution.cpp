class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: Build groups
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Step 2: group -> frequency map
        unordered_map<int, unordered_map<int,int>> mp;

        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;
        }

        // Step 3: compare with target
        int count = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                count++;
            }
        }

        return count;
    }
};
