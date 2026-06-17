class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);

        int diag = 0;
        int antiDiag = 0;

        for(int i = 0; i < moves.size(); i++) {

            int r = moves[i][0];
            int c = moves[i][1];

            int player = (i % 2 == 0) ? 1 : -1; // A = +1, B = -1

            rows[r] += player;
            cols[c] += player;

            if(r == c)
                diag += player;

            if(r + c == 2)
                antiDiag += player;

            if(abs(rows[r]) == 3 ||
               abs(cols[c]) == 3 ||
               abs(diag) == 3 ||
               abs(antiDiag) == 3) {

                return player == 1 ? "A" : "B";
            }
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
