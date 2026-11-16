
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // Starting or ending cell is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;
        q.push({0, 0});

        // 8 directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            if(row == n-1 && col == n-1) {
                return dist[row][col];
            }

            for(int i = 0; i < 8; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow >= 0 && newRow < n &&
                   newCol >= 0 && newCol < n &&
                   grid[newRow][newCol] == 0 &&
                   dist[row][col] + 1 < dist[newRow][newCol]) {

                    dist[newRow][newCol] = dist[row][col] + 1;

                    q.push({newRow, newCol});
                }
            }
        }

        return -1;
    }
};
