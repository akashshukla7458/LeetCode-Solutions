class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if the start or end node is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // Define the eight possible directions
        vector<vector<int>> dir = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        
        // Initialize a queue and a visited matrix
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        
        // Perform BFS on the grid
        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                // Check if we have reached the end node
                if (i == n-1 && j == n-1) {
                    return cnt+1;
                }
                
                // Explore the neighbors of the current node
                for (auto d : dir) {
                    int r = i + d[0], c = j + d[1];
                    if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c] && grid[r][c] == 0) {
                        q.push({r, c});
                        vis[r][c] = true;
                    }
                }
            }
            cnt++;
        }
        
        // If there is no path to the end node, return -1
        return -1;
    }
};
