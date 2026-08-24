class Solution {
public:

    int helper(string &word1, string &word2,
               int m, int n,
               vector<vector<int>>& dp){

        if(m==0) return n;
        if(n==0) return m;

        if(dp[m][n]!=-1)
            return dp[m][n];

        if(word1[m-1]==word2[n-1]){
            return dp[m][n]=helper(word1,word2,m-1,n-1,dp);
        }

        return dp[m][n]=1+min({
            helper(word1,word2,m,n-1,dp),      // Insert
            helper(word1,word2,m-1,n,dp),      // Delete
            helper(word1,word2,m-1,n-1,dp)     // Replace
        });
    }

    int minDistance(string word1, string word2) {

        int m=word1.size();
        int n=word2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return helper(word1,word2,m,n,dp);
    }
};
