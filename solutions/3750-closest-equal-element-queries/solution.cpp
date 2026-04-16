class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i : queries) {
            auto &v = mp[nums[i]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int res = INT_MAX;

            auto it = lower_bound(v.begin(), v.end(), i);

            int idx = it - v.begin();

            // next (circular)
            int next = v[(idx + 1) % v.size()];
            int d1 = abs(next - i);
            res = min(res, min(d1, n - d1));

            // prev (circular)
            int prev = v[(idx - 1 + v.size()) % v.size()];
            int d2 = abs(prev - i);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};
