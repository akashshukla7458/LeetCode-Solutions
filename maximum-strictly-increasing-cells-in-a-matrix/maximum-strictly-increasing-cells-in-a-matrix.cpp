class Solution {
public: 
    int maxIncreasingCells(vector<vector<int>>& g) {
       int n= g.size(), m= g[0].size();
       map<int, vector<pair<int,int>>>mp;
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             mp[g[i][j]].push_back({i,j});
         }
     }
     vector<int>fx(n), fy(m);
     vector<vector<int>>res(n,vector<int>(m));
     int ans=1;
     for(auto &[val,p]: mp){
         for(auto &[x,y]: p){
             res[x][y]= max(fx[x], fy[y])+1;
             ans= max(ans, res[x][y]);
         }
         for(auto &[x,y]:p){
             fx[x]= max(fx[x], res[x][y]);
             fy[y]= max(fy[y], res[x][y]);
         }
     }
     return ans;
    }
};
