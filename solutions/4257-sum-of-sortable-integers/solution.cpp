class Solution {
public:
    bool canBeSorted(vector<int>& a) {
        int n = a.size(), cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > a[(i + 1) % n]) cnt++;
        return cnt <= 1;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;
            for (int i = 0; i < n && ok; i += k) {
                vector<int> sub(nums.begin() + i,
                                nums.begin() + i + k);

                if (!canBeSorted(sub)) {
                    ok = false;
                    break;
                }

                sort(sub.begin(), sub.end());

                for (int j = 0; j < k; j++) {
                    if (sub[j] != sorted[i + j]) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) ans += k;
        }
        return ans;
    }
};
