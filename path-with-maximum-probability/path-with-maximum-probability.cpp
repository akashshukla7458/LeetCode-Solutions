class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int s, int end) {
        vector<pair<int,double>> adj[n+1];
        vector<double>distance(n+1);
        distance[0] = 0;
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], pro[i]});
            adj[edges[i][1]].push_back({edges[i][0], pro[i]});
        }
        
        priority_queue<int> q;
        distance[s] = 1;
        q.push(s);
        while(!q.empty()){
            int p = q.top(); q.pop();
            for(auto x : adj[p]){
                int i = x.first;
                double j = x.second;
                if(distance[p]*j > distance[i]){
                    distance[i] = distance[p]*j;
                    q.push(i);
                }
            }
        }
        return distance[end];
        
    }
};