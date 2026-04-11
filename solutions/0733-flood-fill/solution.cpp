class Solution {
public:
     void dfs(vector<vector<int>>& image, int i, int j, int originalColor, int color) {
        // boundary + color check
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() 
           || image[i][j] != originalColor) {
            return;
        }

        image[i][j] = color; // fill new color

        // 4 directions
        dfs(image, i+1, j, originalColor, color);
        dfs(image, i-1, j, originalColor, color);
        dfs(image, i, j+1, originalColor, color);
        dfs(image, i, j-1, originalColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        // edge case
        if(originalColor == color) return image;

        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
