#include <cstdio>

using ll = long long int;
const int Mod = 1e9 + 7;

ll _power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", _power(a, b));
    }
    return 0;
}