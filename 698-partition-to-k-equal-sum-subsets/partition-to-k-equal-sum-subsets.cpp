class Solution {
public:
int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n= nums.size();
        memset(dp, -1, sizeof(dp));
        dp[0]=0;
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%k!=0) return 0;
        int tar= sum/k;
        
        for(int i=0;i<( 1<<n);i++){
          if(dp[i]==-1) continue;  // invalid 
          for(int j=0;j<n;j++){
              if(!(i &(1<<j)) && dp[i] + nums[j]<= tar){
                  dp[i | (1<<j)]= (dp[i]+ nums[j])%tar;  // set the bit and make it equal to sum
              }
          }
         
        }
        return dp[((1<<n)-1)]==0;
        
    }
};