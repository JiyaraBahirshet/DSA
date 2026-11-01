
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Find all rotten and fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Step 2: Direction vectors
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int minutes = 0;

        // Step 3: Multi-source BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            bool rotten = false;

            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                for(int d = 0; d < 4; d++) {
                    int nr = r + delRow[d];
                    int nc = c + delCol[d];

                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                        rotten = true;
                    }
                }
            }

            if(rotten) minutes++;
        }

        // Step 4: Check if fresh oranges remain
        if(fresh > 0) return -1;

        return minutes;
    }
};
