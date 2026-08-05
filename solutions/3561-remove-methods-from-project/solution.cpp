class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for(auto &e : invocations){
            graph[e[0]].push_back(e[1]);
        }


        // Step 1: find suspicious nodes
        vector<int> suspicious(n,0);

        function<void(int)> dfs = [&](int node){

            suspicious[node] = 1;

            for(int nxt : graph[node]){
                if(!suspicious[nxt])
                    dfs(nxt);
            }
        };


        dfs(k);


        // Step 2: check outside dependency
        for(auto &e : invocations){

            int u = e[0];
            int v = e[1];

            if(!suspicious[u] && suspicious[v]){

                // cannot remove anything
                vector<int> ans;

                for(int i=0;i<n;i++)
                    ans.push_back(i);

                return ans;
            }
        }


        // Step 3: remove suspicious
        vector<int> ans;

        for(int i=0;i<n;i++){

            if(!suspicious[i])
                ans.push_back(i);
        }


        return ans;
    }
};
