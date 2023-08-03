class Solution {
public:
int dp[100005][2];
int solve(vector<int>&nums1, vector<int>&nums2, int i, int prev1, int prev2, bool swap){
    int n= nums1.size();
    if(i==n) return 0;
    if(dp[i][swap]!=-1) return dp[i][swap];
    int ans= INT_MAX;
    
    //no swap
    if(nums1[i]>prev1 && nums2[i]>prev2)
      ans= min(ans, solve(nums1,nums2, i+1, nums1[i], nums2[i], 0));
    if(nums1[i]>prev2 && nums2[i]>prev1)
      ans= min(ans,1+ solve(nums1, nums2, i+1, nums2[i], nums1[i],1));
    return dp[i][swap]= ans;
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1, sizeof(dp));
        return solve(nums1, nums2, 0, -1,-1,0);

    }
};