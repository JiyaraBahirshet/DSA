
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];

        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int,int>>> q;

        vector<int> dist(n, 1e9);

        dist[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(cost + wt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + wt;

                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;

        return dist[dst];
    }
};
