class Solution {
public:
    void helper(vector<vector<char>>& grid,int i ,int j ){

       if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() 
           || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';// mark visited

        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);


    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]== '1'){
                    count++;
                    helper(grid,i,j);
                }
                
            }
        }
        return count;
        
    }
};
