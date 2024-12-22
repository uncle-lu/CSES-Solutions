#include <cstdio>

const int N = 1e6 + 10, mod = 1e9 + 7;
int F[N], line[110], n, x;

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    F[0] = 1;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= n; j++)
            if (i - line[j] >= 0)
                F[i] = (F[i] + F[i - line[j]]) % mod;
    printf("%d", F[x]);
    return 0;
}