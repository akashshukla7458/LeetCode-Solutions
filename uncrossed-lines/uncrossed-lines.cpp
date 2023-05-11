// class Solution {
// public:
//     int dp[501][501]; // increased array size by 1
//     int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
//         if (i == nums1.size() || j == nums2.size()) return 0;
//         if (dp[i][j] != 0) return dp[i][j];

//         int taken = 0;
//         if (nums1[i] == nums2[j]) {
//             taken = 1 + solve(i+1, j+1, nums1, nums2);
//         }
//         int not_taken1 = solve(i+1, j, nums1, nums2);
//         int not_taken2 = solve(i, j+1, nums1, nums2);
//         int not_taken = max(not_taken1, not_taken2);
//         dp[i][j] = max(taken, not_taken);
//         return dp[i][j];
//     }

//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         memset(dp, 0, sizeof(dp));
//         return solve(0, 0, nums1, nums2);
//     }
// };



class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // initialize 2D DP array with zeros

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1; // diagonal + 1
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // max of top and left
                }
            }
        }

        return dp[n][m]; // return the last element in the 2D DP array
    }
};

