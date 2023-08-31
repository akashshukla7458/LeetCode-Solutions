class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,n+2);
        dp[0]=0; // no tap to water nothing

        for(int i=0;i<=n;i++){
            int l= max(0, i-ranges[i]);
            int r= min(n, i+ranges[i]);
            for(int j=l+1; j<=r;j++){
                dp[j]= min(dp[j], 1+ dp[l]);
            }
        }
        return dp[n] >n+1? -1: dp[n];
    }
};
