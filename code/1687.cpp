#include <cstdio>

const int N = 2e5 + 10;
int n, q, d[N][33];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++)
        scanf("%d", &d[i][0]);
    d[1][0] = 0;
    for (int i = 1; i <= 30; i++)
        for (int x = 1; x <= n; x++)
            d[x][i] = d[d[x][i - 1]][i - 1];
    while (q--) {
        int x, k, curr = 0;
        scanf("%d %d", &x, &k);
        while (k != 0) {
            if (k & 1)
                x = d[x][curr];
            curr++;
            k >>= 1;
        }
        printf("%d\n", x == 0 ? -1 : x);
    }
    return 0;
}