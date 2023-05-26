class Solution {
public:


    int stoneGameII(vector<int>& piles) {
        if(piles.empty()) return 0;
        int n= piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1));
        //suffixsum
        vector<int>suffixsum(n+1);
        suffixsum[n-1]= piles[n-1];
        for(int i= n-2;i>=0;i--) suffixsum[i]= piles[i]+ suffixsum[i+1];

        for(int i=n-1;i>=0;i--){
            for(int m=1; m<=n;m++){
                if(i+2*m >=n){
                    dp[i][m]= suffixsum[i];
                }
                else{
                    for(int x=1;x<=2*m;x++){
                        int res= suffixsum[i]- dp[i+x][max(x,m)];
                        dp[i][m]= max(dp[i][m], res);
                    }
                }
            }
        }




   return dp[0][1];





    }
};