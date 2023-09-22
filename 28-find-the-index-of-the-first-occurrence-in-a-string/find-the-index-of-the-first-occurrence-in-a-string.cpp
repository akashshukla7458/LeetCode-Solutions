class Solution {
public:
    int strStr(string A, string B) {
          
        int n = A.size(), m = B.size();
        
        //lps longest prefix-suffix
        vector<int>lps(m);
        int j = 0, i = 1;
        while(i<m){
            if(B[i]==B[j]) lps[i++] = ++j;
            else if(j) j = lps[j-1];
            else lps[i++] = 0;
        }
        
        j = 0, i = 0;
        //using kmp algorithm finding first ocuurence
        while(i<n){
            if(A[i] == B[j]) {  j++, i++; }
            else if(j) j = lps[j-1];
            else i++;
            if(j==m) return i-j;
        }
        
        return -1;
    }
};