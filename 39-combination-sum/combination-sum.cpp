class Solution {
public:
void solve(int idx, vector<int>&temp, vector<vector<int>>&ans, int tar,vector<int>& nums){
    if(idx==nums.size()){
        if(tar==0)
          ans.push_back(temp);
          return;
    }
    if(nums[idx]<=tar){
        temp.push_back(nums[idx]);
        solve(idx,temp, ans, tar-nums[idx], nums);
        temp.pop_back();

    }
    solve(idx+1, temp, ans, tar, nums);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        vector<int>temp;
        vector<vector<int>>ans;
       solve(0,temp, ans, tar, nums);
       return ans;
    }
};