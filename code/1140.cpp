#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 2e5 + 10;
struct node {
    int l, r, p;
    friend bool operator<(const node a, const node b) {
        return a.r < b.r || (a.r == b.r && a.l < b.l);
    }
} line[N];
int n, cnt, number[2 * N];
long long int f[2 * N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &line[i].l, &line[i].r, &line[i].p);
        number[++cnt] = line[i].l;
        number[++cnt] = line[i].r;
    }
    std::sort(number + 1, number + 1 + cnt);
    cnt = std::unique(number + 1, number + 1 + cnt) - number - 1;
    for (int i = 1; i <= n; i++) {
        line[i].l = std::lower_bound(number + 1, number + 1 + cnt, line[i].l) - number;
        line[i].r = std::lower_bound(number + 1, number + 1 + cnt, line[i].r) - number;
    }
    std::sort(line + 1, line + 1 + n);
    int curr = 1;
    for (int i = 1; i <= cnt; i++) {
        while (curr <= n && line[curr].r == i) {
            f[i] = std::max(f[line[curr].l - 1] + line[curr].p, f[i]);
            curr++;
        }
        f[i] = std::max(f[i], f[i - 1]);
    }
    printf("%lld", f[cnt]);
    return 0;
}