#include <cstdio>

const int N = 1e6 + 10;
using ll = long long int;
const ll Mod = 1e9 + 7;
ll fac[N], inv[N];

ll inverse(ll x) {
    ll ans = 1, b = Mod - 2;
    while (b) {
        if (b & 1)
            ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % Mod;
        inv[i] = inverse(fac[i]);
    }
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", fac[a] * inv[b] % Mod * inv[a - b] % Mod);
    }
    return 0;
}