class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n ){
        // vertically
        for(int i =0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        for(int i =row,j =col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i =row,j =col;i>=0 && j>=0;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;

    }
    void helper(int row, int n, vector<string>& board, int& count){
        if(row == n){
            count++;
            return ;
        }

        for(int j= 0;j<n;j++){
            if(isSafe(row,j,board,n)){
                board[row][j]= 'Q';
                helper(row+1,n,board,count);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int count =0;
        helper(0,n,board,count);
        return count;

        
    }
};
