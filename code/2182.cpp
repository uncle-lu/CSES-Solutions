//https://usaco.guide/problems/cses-2182-divisor-analysis/solution
#include <cstdio>

using ll = long long int;
const ll Mod = 1e9 + 7;
const int N = 1e5 + 10;
int n;
ll p[N], c[N];

template <class T> T _power(T a, T b, T m) {
    T ans = 1;
    while (b != 0) {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

template <class T> T _inv(T x, T p) {
    return _power(x, p - 2, p);
}

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &c[i]);
    ll div_cnt = 1, div_sum = 1, div_cnt2 = 1, div_prod = 1;
    for (int i = 1; i <= n; i++) {
        div_cnt = (div_cnt * (c[i] + 1)) % Mod;
        div_sum = div_sum * ((_power(p[i], c[i] + 1, Mod) - 1) % Mod * _inv((p[i] - 1), Mod) % Mod + Mod) % Mod;
        div_prod = _power(div_prod, c[i] + 1, Mod) *
                   _power(_power(p[i], (c[i] * (c[i] + 1) / 2) % (Mod - 1), Mod), div_cnt2, Mod) % Mod;
        div_cnt2 = (div_cnt2 * (c[i] + 1)) % (Mod - 1);
    }
    printf("%lld %lld %lld", div_cnt, div_sum, div_prod);
    return 0;
}