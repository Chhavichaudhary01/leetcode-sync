class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};

        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

        for(auto &p : mp) {
            if(p.first % 2 == 0)
                reverse(p.second.begin(), p.second.end());

            for(int x : p.second)
                ans.push_back(x);
        }

        return ans;
    }
};

