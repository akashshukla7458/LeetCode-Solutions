class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int ans;
        for(auto i :nums) pq.push(i);
        while(k--){
            ans=pq.top();
             pq.pop();
        }
        return ans;
        
    }
};
  