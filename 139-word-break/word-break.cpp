class Solution {
public:
bool solve(string s, unordered_set<string>&st,int idx , vector<int>&dp){
    if(s.size()==idx) return true;
    if(dp[idx]!=-1) return dp[idx];
    for(int i=idx;i<s.size();i++){
        if(st.count(s.substr(idx,i+1-idx))&& solve(s,st,i+1,dp)) return dp[idx]= true;
    }
    return dp[idx]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,-1);
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        return solve(s,st,0,dp);
    }
};