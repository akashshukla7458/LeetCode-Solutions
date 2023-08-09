class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
      sort(nums.begin(),nums.end());
      int n= nums.size(), l=0, r= nums[n-1]-nums[0];
      while(l<=r){
          int m= l+ (r-l)/2, k=0;
          for(int i=1;i<n && k<p;++i){
              if(nums[i]- nums[i-1]<=m){
                  k++; i++;
              }
          }
          if(k>=p) r= m-1;
          else l=m+1;
      }
      return l;
    }
};