class Solution {
public:

    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    void rotate90(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> temp(n , vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][n-i-1] = mat[i][j];
            }
        }
        mat = temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int k=0;k<4;k++){
            if(isEqual(mat , target)) return true;
            rotate90(mat);
        }
        return false;
    }
};
