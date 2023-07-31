class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l= 0, r= nums.size()-1;
        while(l<r){
            int m= l+ (r-l)/2;
            if(nums[m]==k) return m;
            
             // left part sorted
             if(nums[l]<= nums[m] ){
                if(nums[l]<=k && nums[m] >=k){
                    //exists
                    r= m-1;
                }
                else l= m+1;
             }
             else{
                 if(nums[r]>=k && nums[m]<k)
                   l= m+1;
                   else r= m-1;
             }
        }
        return nums[l]==k? l:-1;
    }
};