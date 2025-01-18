#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 510;
long long int f[N][N];
int n, m, q;

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = 1e18;
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long int val;
        scanf("%d %d %lld", &u, &v, &val);
        f[u][v] = std::min(f[u][v], val);
        f[v][u] = std::min(f[u][v], val);
    }
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
                f[x][y] = std::min(f[x][y], f[x][k] + f[k][y]);

    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (f[u][v] == 1e18)
            printf("-1\n");
        else
            printf("%lld\n", f[u][v]);
    }
    return 0;
}