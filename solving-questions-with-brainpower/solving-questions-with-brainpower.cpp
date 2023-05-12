class Solution {
public:

    long long mostPoints(vector<vector<int>>& nums) {
      long long dp[200001]={};
      for(int i=nums.size()-1;i>=0;i--){
          dp[i]= max(nums[i][0]+ dp[nums[i][1]+i+1], dp[i+1]);
      }
      return dp[0];
}
};