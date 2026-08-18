class Solution {
public:

    bool isCycleDfs(int src, vector<vector<int>>& adj,
                    vector<bool>& vis, vector<bool>& recPath,
                    vector<int>& ans) {

        vis[src] = true;
        recPath[src] = true;

        for (int nbr : adj[src]) {

            // Not visited -> DFS
            if (!vis[nbr]) {
                if (isCycleDfs(nbr, adj, vis, recPath, ans)) {
                    return true;
                }
            }

            // Already in current recursion path -> cycle
            else if (recPath[nbr]) {
                return true;
            }
        }

        // DFS for this node is complete
        recPath[src] = false;
        ans.push_back(src);

        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int course = edge[0];
            int prerequisite = edge[1];

            // prerequisite -> course
            adj[prerequisite].push_back(course);
        }

        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                if (isCycleDfs(i, adj, vis, recPath, ans)) {
                    return {};
                }
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
