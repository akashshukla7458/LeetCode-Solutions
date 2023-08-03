class Solution {
public:
const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res={""};
        for(auto digit: digits){
            vector<string>temp;
            for(auto candidate:pad[digit-'0']){
                for(auto s: res)
                   temp.push_back(s+ candidate);
            }
            res.swap(temp);
        }
        return res;
    }
};