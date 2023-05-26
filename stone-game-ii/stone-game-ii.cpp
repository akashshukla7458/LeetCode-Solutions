class Solution {
public:
int solve(vector<int>& piles, vector<vector<int>>&dp, 
const vector<int>&suffixsum, int i, int m){

    if(i==piles.size()) return 0;
    if(i+2*m>= piles.size()) return suffixsum[i];
    if(dp[i][m]!=-1) return dp[i][m];

    int res=0;
    for(int j=1; j<=2*m;j++){
        res= max(res, suffixsum[i]- solve(piles,dp,suffixsum,i+j,max(m,j)));
    }
    dp[i][m]= res;
    return res;
}
    int stoneGameII(vector<int>& piles) {
        if(piles.empty()) return 0;
        int n= piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //suffixsum
        vector<int>suffixsum(n);
        suffixsum[n-1]= piles[n-1];
        for(int i= n-2;i>=0;i--) suffixsum[i]= piles[i]+ suffixsum[i+1];
        return solve(piles,dp,suffixsum,0,1);
    }
};