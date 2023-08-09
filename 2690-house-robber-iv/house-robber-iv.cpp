class Solution {
public:
    int minCapability(vector<int>& a, int k) {
       int l=1, r= 1e9, n=a.size();
       while(l<=r){
           int m= l+ (r-l)/2, take=0;
           for(int i=0;i<n;++i){
               if(a[i]<=m){
                   take++;
                   i++;
               }
           }
           if(take>=k) r= m-1;
           else l= m+1;
       }
       return l;
    }
};