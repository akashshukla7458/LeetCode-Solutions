class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int maxRank = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = int(adj[i].size()) + int(adj[j].size());
                
                for(int neighbor : adj[i]) {
                    if(neighbor == j) {
                        rank--;
                        break;
                    }
                }
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};
