class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Check boundaries and water
        if (row < 0 || row >= m || col < 0 || col >= n ||
            grid[row][col] == '0') {
            return;
        }

        // Mark land as visited
        grid[row][col] = '0';

        // Explore all 4 directions
        dfs(row - 1, col, grid); // Up
        dfs(row + 1, col, grid); // Down
        dfs(row, col - 1, grid); // Left
        dfs(row, col + 1, grid); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};