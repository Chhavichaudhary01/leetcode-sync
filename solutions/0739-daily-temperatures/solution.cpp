class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        int n = temp.size();

        vector<int> ans(n, 0);
        vector<int> next(n, 0);

        // Next Greater Element Index
        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && temp[s.top()] <= temp[i]) {
                s.pop();
            }

            if (s.empty()) {
                next[i] = n;
            } else {
                next[i] = s.top();
            }

            s.push(i);
        }

        // Calculating answer
        for (int i = 0; i < n; i++) {
            if (next[i] == n) {
                ans[i] = 0;
            } else {
                ans[i] = next[i] - i;
            }
        }

        return ans;
    }
};
