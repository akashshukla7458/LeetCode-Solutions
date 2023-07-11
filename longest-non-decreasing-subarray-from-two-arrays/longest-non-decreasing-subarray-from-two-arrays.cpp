class Solution {
public:
 int dp[100005][3];
    int solve(int i, int pArr, vector<int>&nums1, vector<int>&nums2){
    if(i>=nums1.size()) return 0;
    if(dp[i][pArr]!=-1) return dp[i][pArr];
     int ans=0;

     if(pArr==0){
         //no prev arr then 3 cases either no take or take from arr1 or aar2
         ans= max({solve(i+1,0,nums1,nums2), 1+ solve(i+1,1, nums1, nums2),
                   1+ solve(i+1, 2, nums1, nums2)});
         
     }

     // if prev arr ==1;

     else{
         if(pArr==1){
             //check for prev take elment if it is geater than nums1[i] or nums2[i]
             if(nums1[i]>=nums1[i-1]) ans= max(ans, 1+ solve(i+1,1, nums1, nums2));
             if(nums2[i]>= nums1[i-1]) ans= max(ans,1+solve(i+1,2, nums1, nums2));
         }

         else if(pArr==2){
              if(nums1[i]>=nums2[i-1]) ans= max(ans, 1+ solve(i+1,1, nums1, nums2));
             if(nums2[i]>= nums2[i-1]) ans= max(ans,1+solve(i+1,2, nums1, nums2));
         }
     }

     return dp[i][pArr]= ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
       memset(dp,-1, sizeof(dp));
        return solve(0,0, nums1, nums2);
        
        
    }
};