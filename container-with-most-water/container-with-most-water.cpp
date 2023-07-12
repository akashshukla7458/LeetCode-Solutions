class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n= ht.size();
        int i =0, j= ht.size()-1, ans=INT_MIN;
        while(i<j){
            int h=min(ht[i], ht[j]) ;
            ans= max( h* abs(j-i), ans);
            while(ht[i]<= h && i<j) i++;
            while(ht[j] <= h && i<j) j--;
        }
        return ans;
    }
};