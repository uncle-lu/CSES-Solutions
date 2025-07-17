#include <cstdio>

using ll = long long int;
const int N = 1e6 + 10;
const ll Mod = 1e9 + 7;
ll D[N];

int main() {
    int n;
    scanf("%d", &n);
    D[1] = 0;
    D[2] = 1;
    for (int i = 3; i <= n; i++)
        D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % Mod;
    printf("%lld", D[n]);
    return 0;
}