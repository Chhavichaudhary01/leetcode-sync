class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        // horizontally
        for(int j = 0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        // vertically
        for(int i =0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        } 
        // check in grid
        int sr = (row/3)*3;
        int sc = (col/3)*3;
        for(int i =sr;i<=sr+2;i++){
            for(int j = sc;j<=sc+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }

        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){

        if(row == 9){
            return true;

        } 

        int nrow = row,ncol= col+1;
        if(col == 9){
            nrow = row+1;
            ncol =0;
        }


        if(board[row][col]!='.'){
            return helper(board,nrow,ncol);
        }
        // place the digit
        for(char dig = '1' ;dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nrow,ncol)){
                    return true;
                }
                board[row][col]='.';

            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
        
    }
};
