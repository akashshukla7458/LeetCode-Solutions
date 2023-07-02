class Solution {
public:
int ans=0;
void solve(int s, vector<vector<int>>&req, vector<int>&indegree, int n,int cnt){
    if(s==req.size()){
        // all req ended
        for(int i=0;i<n;i++)
            if(indegree[i]!=0) return;
        
        ans= max(ans, cnt);
        return;
    }
     //req remaining
     indegree[req[s][0]]--;
     indegree[req[s][1]]++;
     solve(s+1, req, indegree, n, cnt+1);

     //backtrack
     indegree[req[s][0]]++;
     indegree[req[s][1]]--;
     solve(s+1, req, indegree, n, cnt);


    
}
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int>indegree(n,0);
        solve(0, req, indegree,n, 0);
        return ans;
    }
};