class Solution {
public:
	vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    

double solve(int n, int k , int r, int c, vector<vector<vector<double>>>&dp){
    if(r<0 || r>n-1 || c<0 || c>n-1) return 0;
    if(k==0) return 1;
    if(dp[r][c][k]!=-1) return dp[r][c][k];
    double rate=0;
    for(auto it: dir){
        rate+= 0.125 * solve(n,k-1,r+ it[0], c+ it[1],dp);
    }
    return dp[r][c][k]=rate;
}

    double knightProbability(int n, int k, int row, int col) {
      vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));

        return solve(n,k,row, col,dp);
    }
};