class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc,
             int initialColor, int color) {

        int m = image.size();
        int n = image[0].size();

        // Boundary condition
        if (sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;

        // Check if pixel has a different original color
        if (image[sr][sc] != initialColor)
            return;

        // Change the color
        image[sr][sc] = color;

        // Visit all four directions
        dfs(image, sr - 1, sc, initialColor, color); // Up
        dfs(image, sr + 1, sc, initialColor, color); // Down
        dfs(image, sr, sc - 1, initialColor, color); // Left
        dfs(image, sr, sc + 1, initialColor, color); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int initialColor = image[sr][sc];

        // If original and new colors are same
        if (initialColor == color)
            return image;

        dfs(image, sr, sc, initialColor, color);

        return image;
    }
};