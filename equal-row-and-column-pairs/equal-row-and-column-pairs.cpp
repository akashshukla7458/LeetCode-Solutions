class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
      int cnt=0;
      int n= grid.size();
      for(int i =0;i<n;i++){
          for(int j=0;j<n;j++){
              int k=0;
              while(k<n && grid[i][k]==grid[k][j]) k++;
              cnt+= k==n;
          }
      }
      return cnt;

    }
};