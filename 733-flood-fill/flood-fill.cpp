class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int inicolor, int dr[], int dc[], int color) {
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                image[nrow][ncol] == inicolor && image[nrow][ncol] != color) {
                dfs(image, nrow, ncol, inicolor, dr, dc, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        
        if (inicolor != color) {  // Avoid unnecessary work if color is already the same.
            dfs(image, sr, sc, inicolor, dr, dc, color);
        }
        
        return image;
    }
};
