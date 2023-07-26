class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            double pot = 0; 
            for (int i = 0; i < dist.size(); i++) {
                pot= ceil(pot);
                pot += (double)dist[i] / mid;
            }
           if(pot>hour) l=mid+1;
           else r= mid-1;
        }
        return (l > 1e7) ? -1 : l;
    }
};
