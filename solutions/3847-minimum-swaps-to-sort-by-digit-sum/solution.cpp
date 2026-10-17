class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            arr.push_back({sum, nums[i]});
        }

        sort(arr.begin(), arr.end());

        vector<int> sortedNums(n);

        for (int i = 0; i < n; i++) {
            sortedNums[i] = arr[i].second;
        }

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == sortedNums[i])
                continue;

            int j = pos[sortedNums[i]];

            pos[nums[i]] = j;
            pos[sortedNums[i]] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};
