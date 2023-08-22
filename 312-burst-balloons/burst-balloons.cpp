class Solution {
public:
int dp[301][301];
int n;
int solve(vector<int>&nums, int i , int j){
    if(i>j) return 0;
    if(i==j){
        int temp= nums[i];
        if(i-1>=0) temp*=nums[i-1];
        if(i+1<n) temp*=nums[i+1];
        return temp;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    for(int k=i; k<=j;k++){
        int temp= nums[k]; // last burst adj will be i-1, j+1
        if(j+1<n) temp*=nums[j+1];
        if(i-1>=0) temp*=nums[i-1];
        temp+= solve(nums,i,k-1)+ solve(nums,k+1,j);
        ans= max(ans,temp);
       
    }
   return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
         n=nums.size();
        return solve(nums, 1, n-2);   //first and last are dummy

    }
};