class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int,int>mp;
      for(auto it:nums)
          mp[it]++;
      vector<int>ans;
      priority_queue<pair<int,int>>pq;
      for(auto it:mp)
          pq.push({it.second,it.first});
      while(k--){
          auto [x,y]= pq.top();
          pq.pop();
          ans.push_back(y);
      }
      
      return ans;
    }
};