class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) return;
            grid[i][j] = 2;
            q.push({i, j});
            for (auto d : dir) dfs(i+d[0], j+d[1]);
        };
        
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (auto d : dir) {
                    int nx = x+d[0], ny = y+d[1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (grid[nx][ny] == 1) return ans;
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        return -1; // unreachable
    }
};
