class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();

        // Check boundaries
        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        // If water, stop
        if (grid[r][c] == 0)
            return;

        // Mark visited
        grid[r][c] = 0;

        // Visit four directions
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Check first and last columns
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);

            if (grid[i][n - 1] == 1)
                dfs(grid, i, n - 1);
        }

        // Check first and last rows
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);

            if (grid[m - 1][j] == 1)
                dfs(grid, m - 1, j);
        }

        // Count remaining land cells
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};