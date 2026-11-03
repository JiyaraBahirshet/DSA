
class Solution {
public:
    bool dfs(int node, int target, vector<int>& vis,
             vector<vector<int>>& adj) {

        if(node == target) {
            return true;
        }

        vis[node] = 1;

        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                if(dfs(adjNode, target, vis, adj)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            vector<int> vis(n + 1, 0);

            // Check if u and v are already connected
            if(dfs(u, v, vis, adj)) {
                return {u, v};
            }

            // Add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
