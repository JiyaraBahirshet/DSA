
class Solution {
public:
    bool dfs(int node, int col, vector<int>& color,
             vector<vector<int>>& graph) {

        color[node] = col;

        for(auto adjNode : graph[node]) {

            if(color[adjNode] == -1) {
                if(dfs(adjNode, !col, color, graph) == false) {
                    return false;
                }
            }
            else if(color[adjNode] == col) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                if(dfs(i, 0, color, graph) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
