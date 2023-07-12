class Solution {
public:
bool isBeautiful(string &str,int start,int end)
{
    int res=0,val=1;
    //check leading zeros
    if(str[start]=='0')
    {
        return false;
    }

    //convert into decimal
    for(int i=end;i>=start;i--)
    {
        if(str[i]=='1')
        {
            res+=val;
        }
        val=val*2;
    }

    //check for power of 5
    while(res>1)
    {
        if(res%5==0)
        {
            res=res/5;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
    int solve(string& str,int index,vector<int>&dp)
    {
        if(index==str.size())
        {
            return 0;
        }
        //if(dp[index]!=-1)
        //{
        //    return dp[index];
        //}
  
        //generating substrings
        int mini=INT_MAX-1;
        for(int k=index;k<str.size();k++)
        {
            if(isBeautiful(str,index,k))
            {
                mini=min(mini,1+solve(str,k+1,dp));
            }
        }
        return mini;
        //return dp[index]=mini;
    }
    int minimumBeautifulSubstrings(string str) {
        vector<int>dp(str.size()+1,-1);
        int ans=solve(str,0,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};