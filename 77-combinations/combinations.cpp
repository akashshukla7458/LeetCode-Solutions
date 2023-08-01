class Solution {
public:
vector<vector<int>>ans;
void solve(int idx, int k ,int n, vector<int>&curr){
    if(curr.size()==k){
        ans.push_back(curr);
        return ;
    }
    for(int i= idx;i<n+1;i++){
        curr.push_back(i);
        solve(i+1,k,n,curr);
        curr.pop_back();  //backtrack
    }
}
    vector<vector<int>> combine(int n, int k) {
      vector<int>curr;
      solve(1,k,n,curr);
      return ans;
    }
};