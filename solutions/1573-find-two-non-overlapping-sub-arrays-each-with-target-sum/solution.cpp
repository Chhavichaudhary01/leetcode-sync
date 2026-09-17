class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, 1e9);

        int left = 0;
        int sum = 0;
        int ans = 1e9;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                // Previous non-overlapping subarray
                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Store minimum valid subarray length till right
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }
            } else {
                // No subarray ending at right
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};
