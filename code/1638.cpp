#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1010, mod = 1e9 + 7;
int n, F[N][N];
char maps[N][N];

int main() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", maps[i] + 1);
    if (maps[1][1] != '*')
        F[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (maps[i][j] == '.' && !(i == 1 && j == 1))
                F[i][j] = (F[i - 1][j] + F[i][j - 1]) % mod;
    printf("%d", F[n][n]);
    return 0;
}