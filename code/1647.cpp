#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
int line[N], st[N][30];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++)
        st[i][0] = line[i];
    int t = log(n) / log(2);
    for (int j = 1; j <= t; j++)
        for (int i = 1; i <= n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1)) - 1][j - 1]);

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int k = log(r - l + 1) / log(2);
        //printf("k:%d st[l][k]:%d st[r-(1<<k)][k]:%d ", k, st[l][k], st[r - (1 << k)][k]);
        printf("%d\n", min(st[l][k], st[r - (1 << k) + 1][k]));
    }

    return 0;
}