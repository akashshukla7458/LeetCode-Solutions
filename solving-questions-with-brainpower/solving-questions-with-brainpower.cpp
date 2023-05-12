class Solution {
public:
 long long dp[200001]={};
 long long solve(vector<vector<int>>&nums, long long i ){
     if (i >= nums.size()) {
            return 0;
        }
     if(dp[i]!=-1) return dp[i];
     dp[i]= max(nums[i][0]+ solve(nums,nums[i][1]+1+i),
                solve(nums,i+1));
                
    return dp[i];
 }
    long long mostPoints(vector<vector<int>>& nums) {
    memset(dp,-1,sizeof(dp));
    return solve(nums,0);
}
};