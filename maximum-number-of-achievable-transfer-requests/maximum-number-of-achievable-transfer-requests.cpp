class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& req) {
        int nr= req.size();
        int ans=0;
        for(int mask=0; mask <(1<<nr);mask++){
            vector<int> in(n,0), out(n,0);
            for(int i=0;i<nr;i++){
                if(mask & (1<<i)){
                    out[req[i][0]]++;
                    in[req[i][1]]++;
                }
            }

            if(out==in){
                int temp=0;
                for(auto &v: out) temp+=v;
                ans= max(ans, temp);
            }
        }
        return ans;
    }
};