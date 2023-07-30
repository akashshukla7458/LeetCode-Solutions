class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>&nums, int target) {
       int ans=0;
       for(auto it: nums) ans+= (it>=target);
       return ans;
    }
};