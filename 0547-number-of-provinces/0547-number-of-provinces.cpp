class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;

        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>>& isConnected, int V) {
        vector<int> vis(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, isConnected, vis);
            }
        }

        return count;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        return numProvinces(isConnected, V);
    }
};