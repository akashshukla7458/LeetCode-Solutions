class Solution {
public:

    string stoneGameIII(vector<int>&piles) {
     
     int n= piles.size();
      vector<int>dp(n+1,0);
     
      for(int i =n-1;i>=0;i--){
        int takeone= piles[i] - dp[i+1];
       int taketwo= INT_MIN, takethree= INT_MIN;
        if(i+1<n) taketwo= piles[i]+ piles[i+1] - dp[i+2];
        if(i+2<n) takethree= piles[i]+ piles[i+1]+ piles[i+2] - dp[i+3];
      dp[i]=max({takeone,taketwo,takethree});
      }
      int val=dp[0];


      if(val>0) return "Alice";
      else if(val<0) return "Bob";
      else return "Tie";
    }
};