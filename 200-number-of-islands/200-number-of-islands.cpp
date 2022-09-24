class Solution
{
    public:
        void DFS(vector<vector < char>> &grid, int i, int j,int dr[], int dc[])
        {

            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            {
                return;
            }

            if (grid[i][j] == '0' || grid[i][j] == '2')
            {
                return;
            }

            grid[i][j] = '2';
              
            for(int k =0 ;k<4;k++){
                int nrow= i+dr[k];
                int ncol= j+ dc[k];
                DFS(grid,nrow,ncol,dr,dc);
            }
            // DFS(grid, i - 1, j);
            // DFS(grid, i + 1, j);
            // DFS(grid, i, j - 1);
            // DFS(grid, i, j + 1);
        }

    int numIslands(vector<vector < char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == '1')
                {
                    islands++;
                    DFS(grid, i, j,dr,dc);
                }
            }
        }

        return islands;
    }
};