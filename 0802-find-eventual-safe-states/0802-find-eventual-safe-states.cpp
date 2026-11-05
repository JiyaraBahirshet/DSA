class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<vector<int>> graphrev(v);
        vector<int> indegree(v, 0);

        // Reverse the graph
        for(int i = 0; i < v; i++) {
            for(auto it : graph[i]) {
                graphrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Push terminal nodes (outdegree = 0 in original graph)
        for(int i = 0; i < v; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(auto it : graphrev[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};