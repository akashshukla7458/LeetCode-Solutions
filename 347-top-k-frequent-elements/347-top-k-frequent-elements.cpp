class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>m;
		vector<pair<int,int>> a;
		for(int i=0;i<nums.size();++i){
			m[nums[i]]+=1;
		}
		for(auto x:m){
			a.push_back({x.second,x.first});
		}
		sort(a.rbegin(),a.rend());
		vector<int>ans(k);
		for(int i=0;i<k;++i){
			ans[i] = a[i].second;
		}
		return ans;
    }
};