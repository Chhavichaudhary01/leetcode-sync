class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int maxi = INT_MIN;

        // Insert first element of every list
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (true) {

            auto curr = pq.top();
            pq.pop();

            int mini = curr[0];
            int row = curr[1];
            int col = curr[2];

            // Update answer
            if ((maxi - mini < end - start) ||
                (maxi - mini == end - start && mini < start)) {
                start = mini;
                end = maxi;
            }

            // One list exhausted
            if (col + 1 == nums[row].size())
                break;

            int next = nums[row][col + 1];
            pq.push({next, row, col + 1});

            maxi = max(maxi, next);
        }

        return {start, end};
    }
};
