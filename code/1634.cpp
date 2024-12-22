#include <cstdio>
#include <cstring>

const int N = 1e6;
int f[N];

int main() {
    int n, x, temp;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        for (int j = 1; j <= x; j++) {
            if (j - temp < 0 || (f[j - temp] == 0 && j - temp != 0))
                continue;
            if (f[j] > f[j - temp] + 1 || f[j] == 0)
                f[j] = f[j - temp] + 1;
        }
    }
    if (f[x] == 0)
        printf("-1");
    else
        printf("%d", f[x]);
    return 0;
}