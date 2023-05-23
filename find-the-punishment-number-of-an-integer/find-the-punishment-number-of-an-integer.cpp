class Solution {
public:
    bool solve(string s, int target) {
        if (s == "" && target == 0) return true;
        if (target < 0) return false;

        for (int i = 1; i <= s.size(); i++) {
            int num = stoi(s.substr(0, i));
            if (solve(s.substr(i), target - num)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string s = to_string(sq);
            if (solve(s, i)) sum += sq;
        }

        return sum;
    }
};