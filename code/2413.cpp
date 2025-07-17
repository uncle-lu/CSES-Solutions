#include <cstdio>

const int N = 1e6 + 10, Mod = 1e9 + 7;
long long int F[N][2];

int main() {
    F[1][0] = F[1][1] = 1;
    for (int i = 2; i < N; i++) {
        F[i][1] = (F[i - 1][1] * 4 + F[i - 1][0]) % Mod;
        F[i][0] = (F[i - 1][0] * 2 + F[i - 1][1]) % Mod;
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%lld\n", (F[n][0] + F[n][1]) % Mod);
    }
    return 0;
}