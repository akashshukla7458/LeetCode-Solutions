class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obstacleGrid,int x,int y,int m,int n)
    {
        if(x>=m || y>=n || obstacleGrid[x][y]==1)
            return 0;
        if(x==m-1 && y==n-1)
            return 1;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        else
            dp[x][y] = solve(obstacleGrid,x+1,y,m,n)+solve(obstacleGrid,x,y+1,m,n);
        return dp[x][y];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(obstacleGrid,0,0,m,n);
    }
};