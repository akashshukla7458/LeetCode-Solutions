class Solution {
public:
    typedef long long int ll;
    const ll mod = 1000000007;

    int nthMagicalNumber(int n, int a, int b) {
        int lcm = (a * b) / __gcd(a, b);
        ll l = min(a, b), r = n * 1LL * min(a, b);
        ll ans = 0;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            ll p = m / b + m / a - m / lcm;
            if (p < n)
                l = m + 1;
            else {
                ans = m % mod;
                r = m - 1;
            }
        }
        return ans;
    }
};
