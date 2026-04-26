class Solution {
public:
    int m, n;
    
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == grid[i][j]) {
                
                // agar already visited hai aur parent nahi hai → cycle
                if(vis[ni][nj] && !(ni == pi && nj == pj)) {
                    return true;
                }
                
                if(!vis[ni][nj]) {
                    if(dfs(ni, nj, i, j, grid, vis)) return true;
                }
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }
        
        return false;
    }
};
