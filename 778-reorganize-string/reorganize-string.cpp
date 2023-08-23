class Solution {
public:
    typedef pair<int, int> pi;
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto it : s) 
            mp[it]++;
        
        for (auto it : mp) 
            pq.push({it.second, it.first});
        
        string res = "";
        while (pq.size() > 1) {
            pi t1 = pq.top(); 
            pq.pop();
            
            pi t2 = pq.top(); 
            pq.pop();
            
            res += t1.second; 
            res += t2.second; 
            
            if (--t1.first > 0) 
                pq.push(t1);
            
            if (--t2.first > 0) 
                pq.push(t2);
        }
        
        while (!pq.empty()) {
            if (pq.top().first > 1) 
                return "";
            else 
                res += pq.top().second;
            
            pq.pop();
        }
        
        return res;
    }
};
