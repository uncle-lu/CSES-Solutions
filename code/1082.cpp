#include <cstdio>

using ll = long long int;
const ll Mod = 1e9 + 7;
const ll TWO_MOD_INV = 500000004;

int main() {
    ll n, l = 1, r = 0, res = 0;
    scanf("%lld", &n);
    while (l <= n) {
        r = n / (n / l);
        res = (res + ((r + l) % Mod * ((r - l + 1) % Mod) % Mod * TWO_MOD_INV) % Mod * (n / l) % Mod) % Mod;
        l = r + 1;
    }
    printf("%lld", res);
    return 0;
}