class Solution {
public:
  long long matrixSumQueries(int n, vector<vector<int>>& queries) {
     long long ans=0;
     set<int>r,c;
     reverse(queries.begin(), queries.end());
     for(auto it:queries){
         if(it[0]==0){
                //rows
            if(r.find(it[1])==r.end()){
                ans+= it[2]* (n-c.size());
                r.insert(it[1]);
            }
         }

         else{
             //col
             if(c.find(it[1])==c.end()){
                 ans+= it[2]* (n-r.size());
                c.insert(it[1]);
             }
         }
     }
     return ans;
    }

};