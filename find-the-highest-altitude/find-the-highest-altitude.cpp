class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, mx=0;
        for(auto it:gain){
           mx+= it;
            ans= max(ans, mx);
        }
        
        return ans;
    }
};