class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check same column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1;
            i >= 0 && j >= 0;
            i--, j--) {

            if(board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1;
            i >= 0 && j < n;
            i--, j++) {

            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board,
               vector<vector<string>>& ans, int n) {

        // All queens placed
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for(int col = 0; col < n; col++) {

            if(isSafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next row
                solve(row + 1, board, ans, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};