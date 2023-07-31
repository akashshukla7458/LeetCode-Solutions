class Solution {
public:
vector<vector<int>>dp;
int deadend( string &s, int i){
int sum=0;
 for(;i<s.length();i++)  sum+= (int)s[i];
 return sum;
}
int solve(string &s1, string &s2, int i, int j ){
int n= s1.length(), m= s2.length(), sum=0;
if(i==n || j==m){
    if(i==n && j==m) return 0;
    return (i==n)? deadend(s2,j) : deadend(s1,i);
}
if(dp[i][j]!=-1) return dp[i][j];
if(s1[i]==s2[j]) sum= solve(s1,s2,i+1,j+1);

else{
    sum= min({ solve(s1,s2,i+1,j)+ int(s1[i])
               , solve(s1,s2,i,j+1)+ int(s2[j])
               });
}
return dp[i][j]= sum;


   
}
    int minimumDeleteSum(string s1, string s2) {
      int n= s1.length() , m= s2.length();
      dp.assign(n+1,vector<int>(m+1,-1));
      return solve(s1,s2,0,0);
    }
};