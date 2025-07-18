#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 5010;
int n, line[N];
long long int f[2][N][N], sum[N];

long long int s(int t, int l, int r) {
    return sum[r] - sum[l - 1] - f[t][l][r];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + line[i];
    memset(f, -0x7f, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[0][i][i] = line[i];
    for (int len = 2; len <= n; len++)
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            f[0][l][r] = std::max(s(1, l, r - 1) + line[r], s(1, l + 1, r) + line[l]);
            f[1][l][r] = std::max(s(0, l, r - 1) + line[r], s(0, l + 1, r) + line[l]);
        }
    printf("%lld", n % 2 == 0 ? f[1][1][n] : f[0][1][n]);
    return 0;
}