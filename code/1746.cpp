#include <cstdio>

const int N = 1e5 + 10, M = 110;
const int Mod = 1e9 + 7;
int n, m, line[N];
long long int F[N][M];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);

    if (line[1])
        F[1][line[1]] = 1;
    else
        for (int i = 1; i <= m; i++)
            F[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            F[i][j] += F[i - 1][j];
            if (j != 1)
                F[i][j] += F[i - 1][j - 1];
            if (j != m)
                F[i][j] += F[i - 1][j + 1];
            F[i][j] %= Mod;
        }

        if (line[i]) {
            for (int j = 1; j <= m; j++)
                if (j != line[i])
                    F[i][j] = 0;
        }
    }

    long long int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + F[n][i]) % Mod;
    printf("%lld", ans);
    return 0;
}
