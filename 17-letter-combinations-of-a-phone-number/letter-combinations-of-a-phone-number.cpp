class Solution {
public:
    vector<string> op;
    
    void solve(string digits, vector<string>& pad, int idx, string temp) {
        if (idx == digits.size()) {
            op.push_back(temp);
            return;
        }
        auto val = pad[digits[idx] - '0'];
        for (int i = 0; i < val.size(); i++) {
            temp.push_back(val[i]);  // Push the character from 'val'
            solve(digits, pad, idx + 1, temp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> pad = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, pad, 0, "");
        return op;
    }
};
