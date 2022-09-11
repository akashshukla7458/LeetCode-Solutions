class Solution
{
    public:
        string generate(string s)
        {
            string ans = "";
            unordered_map<char, int> mp;
            for (int i = 0; i <= s.length(); i++)
            {
                if (mp.find(s[i]) == mp.end() && i > 0)
                {
                    auto prev = mp.find(s[i - 1]);
                     ans += to_string(prev->second) + prev->first;                                    mp.clear();
                    }
                 mp[s[i]]++;
                }
                return ans;
            }
            string countAndSay(int n)
            {
                string res = "1";
                for (int i = 1; i < n; ++i)
                {
                    res = generate(res);
                }
                return res;
            }
        };