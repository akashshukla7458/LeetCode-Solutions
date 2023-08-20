class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int k = offers.size();
        vector<int> dp(k + 1, 0);  // Initialize the DP table with zeros
        
        // Sort the offers based on their starting values
        sort(offers.begin(), offers.end());

        // Start populating the DP table from the end
        for (int i = k - 1; i >= 0; i--) {
            vector<int> temp = {offers[i][1], INT_MAX,INT_MAX};
            int ind = lower_bound(offers.begin() + 1, offers.end(), temp) - offers.begin();

            int take = dp[ind] + offers[i][2];
            int nottake = dp[i + 1];
            
            dp[i] = max(take, nottake);
        }
        
        return dp[0];
    }
};
