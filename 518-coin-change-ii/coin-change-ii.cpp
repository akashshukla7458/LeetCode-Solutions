class Solution {
public:
    int dp[301][5001];
    
    int solve(int amt, int n, vector<int>& coins) {
        if (n == 0) return 0;
        if (amt == 0) return 1;
        if (dp[n][amt] != -1) return dp[n][amt]; 
        if (coins[n - 1] > amt) return dp[n][amt] = solve(amt, n - 1, coins);
        return dp[n][amt] =solve(amt - coins[n - 1], n, coins) +
                                solve(amt, n - 1, coins);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(amount, n, coins);
    }
};
