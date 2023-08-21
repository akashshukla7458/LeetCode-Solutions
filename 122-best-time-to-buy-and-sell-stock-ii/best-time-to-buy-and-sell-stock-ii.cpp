class Solution {
public:
vector<vector<int>>dp;
int solve(vector<int>&prices, int i, bool buy){
    int n= prices.size();
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit;
    if(buy==0){
        profit= max(solve(prices,i+1,0) , -prices[i]+ solve(prices,i+1,1));
    }
    if(buy==1){
        profit= max(solve(prices,i+1,1), prices[i]+ solve(prices, i+1,0));
    }
   return dp[i][buy]= profit;

}
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        dp.resize(n+1, vector<int>(2,-1));
        if(n==0) return 0;
        return solve(prices, 0, 0);
    }
};