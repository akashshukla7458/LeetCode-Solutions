class Solution {
public:

 bool solve(vector<int>& a,int sum,int part,int k, vector<bool>&vis,int index,int n)
    {
        if(k==0) return true;
        if(sum>part) return false;
        if(sum==part) {
            return solve(a,0,part,k-1,vis,0,n);
        }
        
        for(int i=index;i<n;i++)
        {
            if(vis[i]) continue;
            
            vis[i]=true;
            if(solve(a,sum+a[i],part,k,vis,i+1,n)) return true;
            
            vis[i]=false;
        }
        
        return false;
    }
  
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n= a.size();
        int sum = 0;
         for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         
         if(sum%k!=0) return false;
         
       vector<bool>vis(n,0);
         
         return solve(a,0,sum/k,k,vis,0,n);
    }
};