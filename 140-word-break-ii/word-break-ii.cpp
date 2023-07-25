class Solution {
public:
void solve(int idx, string s, string curr,unordered_set<string>&set,   vector<string>&res ){
    if(idx==s.size()){
        curr.pop_back();
        res.push_back(curr);
    }
    string str="";
    for(int i= idx;i<s.length();i++){
        str.push_back(s[i]);
        if(set.count(str)){
            solve(i+1,s,curr+str+" ",set,res);
        }
    }

}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set(wordDict.begin(), wordDict.end());
        vector<string>res;
        solve(0,s,"",set,res);
        return res;

    }
};