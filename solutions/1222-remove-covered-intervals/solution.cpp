class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];   // right descending
                 return a[0] < b[0];       // left ascending
             });

        int count = 0;
        int maxRight = -1;

        for (auto &it : intervals) {
            if (it[1] > maxRight) {
                count++;
                maxRight = it[1];
            }
        }

        return count;
    }
};
