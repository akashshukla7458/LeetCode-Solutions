class Solution {
public:
    string convertToTitle(int n) {
    return n == 0 ? "" : convertToTitle(--n / 26) + (char)('A' + (n % 26));
    }
};