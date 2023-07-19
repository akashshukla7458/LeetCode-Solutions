class Solution {
public:
  bool static comp(vector<int>&a, vector<int>&b){
      return a[1] <b[1];
  }
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);
        int ans=-1;
        vector<int>prev= intervals[0];
        for(auto i:intervals){
            if(prev[1]>i[0]){
                ans++;
            }
            else prev=i;
        }
        return ans;
       

    }
};