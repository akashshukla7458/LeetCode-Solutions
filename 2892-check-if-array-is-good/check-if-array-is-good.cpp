class Solution {
public:
    bool isGood(vector<int>& nums) {
       vector<int>freq(202,0);
       for(auto it:nums) freq[it]++;
       if(freq[nums.size()-1]!=2) return false;
       for(int i=1;i<nums.size()-1;i++)
         if(freq[i]!=1) return false;
    return true;
    }

};