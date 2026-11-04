class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // cost[i] = operations to make all elements equal in nums[i ... i + x - 1]
        vector<long long> cost(n - x + 1, 0);
        
        multiset<long long> lower, upper;
        long long lower_sum = 0, upper_sum = 0;
        
        auto balance = [&]() {
            while (lower.size() > upper.size() + 1) {
                auto it = prev(lower.end());
                long long val = *it;
                lower_sum -= val;
                lower.erase(it);
                upper.insert(val);
                upper_sum += val;
            }
            while (lower.size() < upper.size()) {
                auto it = upper.begin();
                long long val = *it;
                upper_sum -= val;
                upper.erase(it);
                lower.insert(val);
                lower_sum += val;
            }
        };
        
        auto add_element = [&](long long val) {
            if (lower.empty() || val <= *lower.rbegin()) {
                lower.insert(val);
                lower_sum += val;
            } else {
                upper.insert(val);
                upper_sum += val;
            }
            balance();
        };
        
        auto remove_element = [&](long long val) {
            auto it = lower.find(val);
            if (it != lower.end()) {
                lower_sum -= val;
                lower.erase(it);
            } else {
                it = upper.find(val);
                upper_sum -= val;
                upper.erase(it);
            }
            balance();
        };

        // Step 1: Sliding window to calculate median cost for each window of length x
        for (int i = 0; i < n; ++i) {
            add_element(nums[i]);
            
            if (i >= x) {
                remove_element(nums[i - x]);
            }
            
            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long cur_cost = (median * (long long)lower.size() - lower_sum) + 
                                     (upper_sum - median * (long long)upper.size());
                cost[i - x + 1] = cur_cost;
            }
        }

        // Step 2: Dynamic programming to select k non-overlapping subarrays
        const long long INF = 1e18;
        // dp[i][j] = min cost using j subarrays chosen from prefix nums[0 ... i - 1]
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                // Choice 1: Skip nums[i - 1]
                dp[i][j] = dp[i - 1][j];
                
                // Choice 2: Pick subarray nums[i - x ... i - 1]
                if (j > 0 && i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};
