class Solution {
public: 
    bool isSafe(int row, int col,vector<string>&board,int n){
        //horizontally
        for(int j =0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }


        }

        // vertically
        for(int i =0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        } 
        // diagonally
        //left diagonal
        for(int i = row,j =col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                 return false;

            }
           
        }

        // right diagonal
        for(int i = row,j =col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                 return false;

            }
           
        }
        return true;
    }
    void nQueen(int row, int n,vector<string>&board, vector<vector<string>>&ans){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        for(int j = 0;j<n;j++){
            if(isSafe(row,j,board,n)){
                board[row][j]='Q';
                nQueen(row+1,n,board,ans); //next row
                board[row][j] = '.'; //backTracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        nQueen(0,n,board,ans);
        return ans;

    }
};
