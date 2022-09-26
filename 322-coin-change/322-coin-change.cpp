class Solution
{
    public:
        int f(vector<int> &nums, int targ, int i, vector<vector< long long int>> &dp)
        {
            if (i == 0)
            {
                if (targ % nums[i] == 0)
                    return dp[i][targ] = targ / nums[i];
                else
                    return 1e9;
            }

            if (dp[i][targ] != -1) return dp[i][targ];

            int not_take = 0 + f(nums, targ, i - 1, dp);
            int take = INT_MAX;

            if (nums[i] <= targ)
            {
                take = 1 + f(nums, targ - nums[i], i, dp);
            }

            return dp[i][targ] = min(take, not_take);
        }

    int coinChange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector < long long int>> dp(n + 1, vector < long long int > (target + 1, -1));
        long long int ans = f(nums, target, n - 1, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};