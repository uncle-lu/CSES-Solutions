#include <cstdio>

using ll = long long int;
const int N = 2e6 + 10;
const ll Mod = 1e9 + 7;
ll fac[N], inv[N];
int n, m;

ll inverse(ll x) {
    ll ans = 1, b = Mod - 2;
    while (b != 0) {
        if (b & 1)
            ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % Mod;
        inv[i] = inverse(fac[i]);
    }
    scanf("%d %d", &n, &m);
    printf("%lld", fac[n + m - 1] * inv[m] % Mod * inv[n - 1] % Mod);
    return 0;
}