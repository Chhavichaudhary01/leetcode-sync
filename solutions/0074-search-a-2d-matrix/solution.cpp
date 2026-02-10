class Solution {
public:
    bool searchR(vector<vector<int>>& mat, int target,int row){
        // search only ion single row of coloumn
        int n = mat[0].size();
        int st =0,end = n-1;
        while(st<=end){
            int mid = st+ (end - st)/2;
            if(target == mat[row][mid]){
                return true;
            }
            else if(target>mat[row][mid]){
                st = mid+1;
            }else{
                end = mid -1;
            }

            
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int st =0,end = m-1;
        while(st<=end){
            int midR = st+(end - st)/2;

            if(target >= mat[midR][0] && target <= mat[midR][n-1]){
                return searchR(mat,target,midR);

            }
            
        
            else if(target<= mat[midR][0]){
                // upward => left
                end = midR-1;
            }else{
                st = midR+1;
            }



        }
        return false;
        
    }
};
