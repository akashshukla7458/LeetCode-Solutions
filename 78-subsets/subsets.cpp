class Solution {
public:
void solve(vector<int>&nums, int i , vector<int>&temp, vector<vector<int>>&ans){
      ans.push_back(temp);
      for(int j=i;j<nums.size();j++){
          temp.push_back(nums[j]);
          solve(nums,j+1,temp, ans);
          temp.pop_back();
      }

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,0,temp,ans);
        return ans;
    }
};