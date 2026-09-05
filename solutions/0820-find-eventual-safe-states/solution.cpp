class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {

        vis[node] = 1;   // currently visiting

        for(int v : graph[node]) {

            // Cycle found
            if(vis[v] == 1)
                return false;

            // v is unsafe
            if(vis[v] == 0 && !dfs(v, graph, vis))
                return false;
        }

        // Node is safe
        vis[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            if(dfs(i, graph, vis))
                ans.push_back(i);
        }

        return ans;
    }
};
