class Solution {
public:
bool valid(string temp){
    if(temp.size()>3 || temp.size()==0) return false;
    if(temp.size()>1 && temp[0]=='0') return false;
    if(temp.size() && stoi(temp)> 255 ) return false;
    return true;
}
void solve(vector<string>&ans, string res, int ind, string s, int dots){
    if(dots==3){
        if(valid(s.substr(ind)))
           ans.push_back(res+s.substr(ind));
           return;
    }
    int sz= s.size();
    for(int i= ind;i< min(ind+3,sz);i++){
        if(valid(s.substr(ind, i-ind+1))){
            res.push_back(s[i]);
            res.push_back('.');
            solve(ans,res, i+1,s, dots+1);
            res.pop_back();
        }
    }
}
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string res;
        solve(ans,res,0,s,0);
        return ans;
    }
};