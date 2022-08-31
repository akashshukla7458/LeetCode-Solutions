class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merge;
         double n=0.0;
       for(auto i :nums1) merge.push_back(i);
       for(auto j:nums2) merge.push_back(j);
        sort(merge.begin(),merge.end());
        int mid= (0+merge.size())/2;
       
        if(merge.size()%2!=0) n=merge[mid];
        else n= ((double) merge[mid] + (double) merge[mid-1])/2;
        return n;
    }
};