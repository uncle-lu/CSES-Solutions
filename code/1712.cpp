#include <cstdio>

using ll = long long int;
const int Mod = 1e9 + 7;

ll _power(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans % m;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", _power(a, _power(b, c, Mod - 1), Mod));
    }
    return 0;
}