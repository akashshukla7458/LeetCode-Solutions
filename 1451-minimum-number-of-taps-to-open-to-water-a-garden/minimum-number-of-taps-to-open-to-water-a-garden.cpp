class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i <= n; ++i) {
            intervals.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});
        }
        
        
        sort(intervals.begin(), intervals.end());

     
        int taps = 0; 
        int currentPosition = 0; 
        int nextPosition = 0; 
        
        for (int i = 0; i <= n; ) {
            // Check if there's an interval covering currentPosition
            while (i <= n && intervals[i].first <= currentPosition) {
                nextPosition = max(nextPosition, intervals[i].second);
                ++i;
            }
            
            // If no interval found covering currentPosition, return -1
            if (nextPosition == currentPosition) {
                return -1;
            }
            
            // Increment taps used and update currentPosition
            ++taps;
            currentPosition = nextPosition;
            
            // If we've reached the end of the garden, break the loop
            if (currentPosition >= n) {
                break;
            }
        }
        
        return taps;
    }
};
