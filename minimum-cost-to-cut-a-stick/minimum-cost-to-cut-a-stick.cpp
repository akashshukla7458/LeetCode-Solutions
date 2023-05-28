class Solution {
public:
   int dp[101][101];
int helper(vector<int>&cuts, int l, int r, int ci, int cj){
    if(ci>cj) return 0;
    if(dp[ci][cj]!=-1) return dp[ci][cj];
    int cost=INT_MAX;
    for(int k= ci; k<=cj;k++){
        cost= min(cost,helper(cuts,l,cuts[k],ci,k-1) +
         helper(cuts,cuts[k],r, k+1,cj));
    }
      return dp[ci][cj] = cost+r-l;

}
    int minCost(int n, vector<int>& cuts) {
       memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        int ci=0;
        int cj=cuts.size()-1;
        return helper(cuts,0,n,ci,cj);
    }
};