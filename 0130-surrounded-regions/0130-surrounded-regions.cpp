
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board,
             int m, int n) {

        board[r][c] = '#';

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int d = 0; d < 4; d++) {
            int nr = r + delRow[d];
            int nc = c + delCol[d];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               board[nr][nc] == 'O') {

                dfs(nr, nc, board, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Step 1: First and last columns
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board, m, n);
            }

            if(board[i][n-1] == 'O') {
                dfs(i, n-1, board, m, n);
            }
        }

        // Step 2: First and last rows
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board, m, n);
            }

            if(board[m-1][j] == 'O') {
                dfs(m-1, j, board, m, n);
            }
        }

        // Step 3: Convert the board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
