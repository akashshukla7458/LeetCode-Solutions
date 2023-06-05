class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        int x0= cord[0][0];
        int y0= cord[0][1];
        int x1= cord[1][0];
        int y1= cord[1][1];
        
        for(int i=2;i<cord.size();i++){
            int x= cord[i][0], y= cord[i][1];
            if((x-x0)* (y1-y0)!= (y-y0)* (x1-x0)) return 0;
        }
        return 1;
    
    }
};