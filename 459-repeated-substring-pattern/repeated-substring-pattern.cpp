class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i=n/2;i>0;i--){
          if(n%i==0){
            if(s.substr(i)==s.substr(0,n-i)) return true;
          }
        }
        return 0;
    }
};