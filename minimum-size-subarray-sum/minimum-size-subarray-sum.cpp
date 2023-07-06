class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //prefix sum approach


        // int len=INT_MAX, n=nums.size();
        // vector<int>sum(n+1);
        
        // for(int i =1;i<=n;i++){
        //     sum[i]=sum[i-1]+ nums[i-1];
        // }
        // for(int i=n;i>=0 && sum[i]>=target;i--){
        //     int j= upper_bound(sum.begin(),sum.end(),sum[i]-target)-sum.begin();
        //     len= min(len,i-j+1);
        // }
        // return len<INT_MAX? len:0;



        // sliding window approach


       int i=0, j=0,sum=0,len=INT_MAX;
       int n=nums.size();
       while(j<n){
           sum+=nums[j++];
           while(sum>=target){
               len= min(len,j-i);
               sum-=nums[i++];
           }
       }
       return len<INT_MAX?len:0;

    }
};