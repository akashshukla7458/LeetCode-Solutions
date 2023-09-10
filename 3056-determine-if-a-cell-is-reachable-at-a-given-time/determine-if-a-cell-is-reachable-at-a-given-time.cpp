class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fxx, int fy, int t) {
        long long int xx=abs(sx-fxx);
        long long int yy=abs(sy-fy);
        long long int gg=max(xx,yy);
        if(gg>t || (gg==0 &&(t==1)))
        {
            return false;
        }
        else{
            
            return true;
        }
    }
};