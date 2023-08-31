class Solution {
public:
    int jump(vector<int>& nums) {
       int currend=0, maxreach=0, cnt=0, n= nums.size();
       for(int i=0;i<n-1;i++){
           maxreach= max(maxreach, nums[i]+i);
           if(i==currend){
               currend= maxreach;
               cnt++;
               
           }
       }
       return cnt;
    }
};