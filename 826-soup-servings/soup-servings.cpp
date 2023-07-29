class Solution {
public:
    double dfs(int A, int B, vector<vector<double>>& dp) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        else if (B <= 0) return 0.0;
        
        if (dp[A][B] != -1.0) return dp[A][B];
        
        dp[A][B] = 0.25 * (dfs(A - 4, B, dp) + dfs(A - 3, B - 1, dp) + dfs(A - 2, B - 2, dp) + dfs(A - 1, B - 3, dp));
        return dp[A][B];
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0; // Handle edge case for large n to improve efficiency
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1.0));
        n= ceil(1.0*n/25);
        return dfs(n, n, dp);
    }
};
