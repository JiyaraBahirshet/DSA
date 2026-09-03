class Solution {
public:

    bool solve(int r, int c, int idx, vector<vector<char>>& board,
               string& word) {

        // All characters matched
        if (idx == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size())
            return false;

        // Current cell doesn't match
        if (board[r][c] != word[idx])
            return false;

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Move in 4 directions
        bool found =
            solve(r + 1, c, idx + 1, board, word) ||
            solve(r - 1, c, idx + 1, board, word) ||
            solve(r, c + 1, idx + 1, board, word) ||
            solve(r, c - 1, idx + 1, board, word);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Try every cell as starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {

                    if (solve(i, j, 0, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};