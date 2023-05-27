class Solution {
public:
int solve(vector<int>&piles, int i, vector<int>&dp){
int n= piles.size();
if(i>=n) return 0;
if(dp[i]!=INT_MAX) return dp[i];

int takeone= piles[i] - solve( piles,i+1,dp);
int taketwo= INT_MIN, takethree= INT_MIN;
if(i+1<n) taketwo= piles[i]+ piles[i+1] - solve(piles,i+2,dp);
if(i+2<n) takethree= piles[i]+ piles[i+1]+ piles[i+2] - solve( piles,i+3,dp);
return dp[i]=max({takeone,taketwo,takethree});

}
    string stoneGameIII(vector<int>&piles) {
      vector<int>dp(piles.size(),INT_MAX);
      int val= solve(piles,0,dp);
      if(val>0) return "Alice";
      else if(val<0) return "Bob";
      else return "Tie";
    }
};