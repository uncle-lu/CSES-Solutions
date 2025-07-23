#include <algorithm>
#include <cstdio>

const int N = 30, M = (1 << 20) + 10;
int n, k, line[N], f[M], sum[M];

bool in(int x, int t) {
    return x & (1 << (t - 1));
}

int add(int x, int t) {
    return x | (1 << (t - 1));
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 0; i <= (1 << n) - 1; i++) {
        f[i] = 0x7f7f7f7f;
        sum[i] = k;
    }
    f[0] = 0;
    for (int now = 0; now <= (1 << n) - 1; now++) {
        for (int i = 1; i <= n; i++) {
            if (in(now, i))
                continue;
            int tempf = f[now] + (sum[now] - line[i] < 0 ? 1 : 0);
            int temps = sum[now] - line[i] >= 0 ? sum[now] - line[i] : k - line[i];
            if (f[add(now, i)] > tempf || (f[add(now, i)] == tempf && sum[add(now, i)] < temps)) {
                f[add(now, i)] = tempf;
                sum[add(now, i)] = temps;
            }
        }
    }
    printf("%d", f[(1 << n) - 1] + 1);
    return 0;
}