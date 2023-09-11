class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>>ans{};
        unordered_map<int, vector<int>>mp{};
        for(int i=0;i<nums.size();i++){
            int key= nums[i];
            if(mp.count(key)){
                mp[key].push_back(i);
            }
            else
               mp[key]= vector<int>{i};
            if(mp[key].size()==key){
                ans.push_back(mp[key]);
                mp.erase(key);
            }
        }
        return  ans;
    }
};