
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // Step 1: Push all zero cells into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Step 2: Direction vectors
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Step 3: Multi-source BFS
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int d = 0; d < 4; d++) {
                int nr = r + delRow[d];
                int nc = c + delCol[d];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};
