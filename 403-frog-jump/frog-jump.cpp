class Solution {
public:
int dp[2001][2001];
 bool solve(int i,int k, vector<int>&stones,unordered_map<int,int>&mp ){
  if(k<=0) return 0;
  if(mp.find(k+ stones[i-1])==mp.end()) return 0;
  else 
        i=mp[k+stones[i-1]];
   if(dp[i][k]!=-1) return dp[i][k];
   if(i==stones.size()-1) return 1;
   dp[i][k]= solve(i+1,k-1,stones,mp) || solve(i+1,k,stones, mp) || solve(i+1,k+1, stones, mp);

   return dp[i][k];

}
    bool canCross(vector<int>& stones) {
        memset(dp,-1, sizeof(dp));
        int n= stones.size();
        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++)
             mp[stones[i]]=i;
    if(stones[1]!=1) return 0;
       return  solve(1,1,stones,mp);
    }
};