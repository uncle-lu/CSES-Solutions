#include <algorithm>
#include <cstdio>

const int N = 510;
int a, b, f[N][N];

int main() {
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j)
                continue;
            f[i][j] = 0x7f7f7f7f;
            for (int k = 1; k <= std::min(i, j); k++) {
                if (k == i)
                    f[i][j] = std::min(f[i][j], f[i][j - k] + 1);
                else if (k == j)
                    f[i][j] = std::min(f[i][j], f[i - k][j] + 1);
                else
                    f[i][j] = std::min({f[i][j], f[i][j - k] + f[i][k] + 1, f[i - k][j] + f[k][j] + 1});
            }
        }
    }
    printf("%d", f[a][b]);
    return 0;
}