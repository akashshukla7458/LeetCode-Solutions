class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        int curr=INT_MAX, res=0;
        for(int i=n-1;i>=0;i--){
            if(pairs[i][1] <curr){
                curr= pairs[i][0];
                res++;
            }
        }
        return res;
    }
};