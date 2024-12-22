#include <cstdio>

const int N = 1e6 + 10, mod = 1e9 + 7;
int F[N], line[110], n, x;

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    F[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            if (j - line[i] >= 0)
                F[j] = (F[j] + F[j - line[i]]) % mod;
    printf("%d", F[x]);
    return 0;
}