//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int assignMiceHoles(int N , int M[] , int H[]) {
        // code here
        sort(H,H+N);
        sort(M,M+N);
        int res=0;
        for(int i=0;i<N;i++){
        if(res < abs(M[i]-H[i]))    res= abs(M[i]-H[i]);
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        
        int M[N],H[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>M[i];
        for(int i=0 ; i<N ; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.assignMiceHoles(N,M,H) << endl;
    }
    return 0;
}
// } Driver Code Ends