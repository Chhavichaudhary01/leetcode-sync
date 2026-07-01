class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Count fresh oranges and push all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If there are no fresh oranges
        if (fresh == 0)
            return 0;

        int minutes = 0;

        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // BFS
        while (!q.empty()) {

            int size = q.size();
            bool rottenThisMinute = false;

            while (size--) {

                auto node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                // Check all 4 directions
                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;

                        rottenThisMinute = true;
                    }
                }
            }

            if (rottenThisMinute)
                minutes++;
        }

        if (fresh > 0)
            return -1;

        return minutes;
    }
};
