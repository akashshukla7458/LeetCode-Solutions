class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        for(auto ch: s)
          mp[ch]++;
        priority_queue<int>pq;
        for(auto &it: mp)
         pq.push(it.second);

         int cnt=0;
         while(pq.size()!=1){
             int top= pq.top();
             pq.pop();
             if(pq.top()==top && top!=0){
                 cnt++;
                 pq.push(top-1);
             }
         }
         return cnt;
    }
};