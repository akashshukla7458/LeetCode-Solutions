class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int t=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) t++;
            }
        }
        if(t==0) return 0;
        int ans= INT_MAX;

        for(int i=0;i<3;++i){
            for(int j =0;j<3;++j){
                    if(grid[i][j]==0){
                        for(int nr=0;nr<3;nr++){
                            for(int nj=0;nj<3;nj++){
                                int d= abs(nr-i) + abs(nj-j);
                                if(grid[nr][nj]>1){
                                      grid[nr][nj]--;
                                    grid[i][j]++;
                                    ans= min(ans, d+ minimumMoves(grid));
                                    grid[nr][nj]++;
                                    grid[i][j]--;
                                }
                            }
                        }
                    }
            }
        }
        return ans;
    }
};