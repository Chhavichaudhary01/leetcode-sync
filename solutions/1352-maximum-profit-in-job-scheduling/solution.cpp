class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int solve(int i) {
        if (i >= jobs.size()) return 0;

        if (dp[i] != -1) return dp[i];

        // Binary search for next non-overlapping job
        int l = i + 1, r = jobs.size() - 1;
        int next = jobs.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (jobs[mid][0] >= jobs[i][1]) {
                next = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int take = jobs[i][2] + solve(next);
        int skip = solve(i + 1);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        dp.assign(n, -1);

        return solve(0);
    }
};
