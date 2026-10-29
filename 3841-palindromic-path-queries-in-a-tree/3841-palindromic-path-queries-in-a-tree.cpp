class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);
        vector<int> rootMask(n, 0);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            up[0][u] = p;

            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            rootMask[u] = (p == u ? 0 : rootMask[p])
                          ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer - 1;
        };

        dfs(0, 0);

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<int> bit(n + 2, 0);

        auto updateBIT = [&](int idx, int val) {
            for (idx++; idx <= n + 1; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        };

        auto queryBIT = [&](int idx) {
            int res = 0;

            for (idx++; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }

            return res;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            updateBIT(l, val);
            updateBIT(r + 1, val);
        };

        vector<bool> answer;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a'))
                          ^ (1 << (c - 'a'));

                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } 
            else {
                int v;
                ss >> v;

                int l = lca(u, v);

                int maskU = rootMask[u] ^ queryBIT(tin[u]);
                int maskV = rootMask[v] ^ queryBIT(tin[v]);

                int pathMask = maskU ^ maskV
                             ^ (1 << (s[l] - 'a'));

                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};