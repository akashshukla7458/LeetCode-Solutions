class Solution {
public:
int ans= INT_MAX;
void solve( int start, vector<int>&nums, vector<int>&v, int k){
    if(start== nums.size()){
        int max_val= INT_MIN;
        for(int i=0;i<k;i++) max_val= max(max_val, v[i]);
        ans= min(ans, max_val);
        return;
    }
    for(int i=0;i<k;i++){
        v[i] +=nums[start];
        solve(start+1,nums,v,k);
        v[i]-= nums[start]; // backtrack;
    }
}
    int distributeCookies(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>v(k,0);
        solve(0,nums,v,k);
        return ans;
    }
};