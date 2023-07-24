class Solution {
public:
    string sortVowels(string s) {
        vector<char> vow;
        vector<int> pos;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                vow.push_back(s[i]);
                pos.push_back(i);
            }
        }

        sort(vow.begin(), vow.end());
        string ans = s;
        for (int i = 0; i < pos.size(); i++) {
            ans[pos[i]] = vow[i];
        }
        return ans;
    }
};
