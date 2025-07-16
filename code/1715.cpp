#include <cstdio>
#include <cstring>

using ll = long long int;
const ll Mod = 1e9 + 7;
const int N = 1e6 + 7;
ll fac[N];
int tong[30];
char str[N];

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
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % Mod;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        tong[str[i] - 'a']++;
    ll ans = fac[len];
    for (int i = 0; i < 26; i++)
        ans = ans * inverse(fac[tong[i]]) % Mod;
    printf("%lld", ans);
    return 0;
}