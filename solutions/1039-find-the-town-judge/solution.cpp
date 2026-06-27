class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        for(auto &x : trust){
            outdegree[x[0]]++;
            indegree[x[1]]++;
        }

        for(int i = 1; i <= n; i++){
            if(indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
        }

        return -1;
    }
};
