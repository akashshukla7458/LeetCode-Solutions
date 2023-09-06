class Solution {
public:
    string reverseWords(string s) {
         stringstream is(s);
         string str, ans="";
         int i=0;
         while(is>>str){
             if(i==0){
                 ans= str+ ans;
             }
             else{
                 ans= str+ " "+ ans;
             }
             i++;
         }
         return ans;
    }
};