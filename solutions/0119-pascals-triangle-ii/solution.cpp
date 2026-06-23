class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> ans;

        long long val = 1;
        ans.push_back(1);

        for (int col = 1; col <= rowIndex; col++) {

            val = val * (rowIndex - col + 1) / col;

            ans.push_back(val);
        }

        return ans;
    }
};
