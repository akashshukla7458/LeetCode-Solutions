class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp, all;
        for(auto it:nums) all[it]++;
        int i=0, j=0, ans=0;
        while(i<nums.size()){
            mp[nums[i]]++;
            while(j<=i && mp.size()==all.size()){
                if(--mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
                ans+= nums.size()- i;
            }
            i++;
        }
        return ans;
    }
};