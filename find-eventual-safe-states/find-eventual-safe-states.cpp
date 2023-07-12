class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>>adj(n);
        vector<int>out(n), safe(n), ans;
        queue<int>q;
        for(int i =0;i<n;i++){
            for(auto v: graph[i])
                adj[v].push_back(i);
            
            out[i]= graph[i].size();
            if(out[i]==0) q.push(i);  // terminal node
        }

        while(!q.empty()){
            int u = q.front(); q.pop();
            safe[u]=1;
            for(auto v: adj[u]){
                if(--out[v]==0) q.push(v);
            }
        }

        for(int i=0;i<n;i++)
           if(safe[i]) ans.push_back(i);

        return ans;

    }
};