class Solution {
public:
typedef long long ll;
const int MOD= 1e9+7;
int dp[101][101];
ll solve(int n, int goal , int k){
    if(n==0 && goal==0) return 1;
    if(n==0|| goal==0) return 0;
    if(dp[n][goal]!=-1) return dp[n][goal];
    ll pick= solve(n-1,goal-1,k) *n;
    ll not_pick= solve(n,goal-1,k)* max(n-k,0);
    return dp[n][goal]= (pick+ not_pick)%MOD;
}
// notpick means that, for resolving the above "k other songs" problem, if we really want to put the same song into the playlist again, we have to fill k other songs between the two same songs first.

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1, sizeof(dp));
        return solve(n,goal,k);
    }
};