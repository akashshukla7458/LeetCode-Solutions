class Solution {
public:
    long long maxRunTime(int n, vector<int>& nums) {
        long long l=0, r= accumulate(nums.begin(), nums.end(),0LL)/n;
        //r is avg time
        while(l<r){
            long long m= (l+r+1)/2, minutes=0;
            for(auto it: nums)
               minutes+= min((long long)it,m);
               if(minutes>= n*m)
                 l=m;
                 else r= m-1;
        }
        return l;
    }
};