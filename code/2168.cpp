#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int l, r, sit;
    friend bool operator<(const node a, const node b) {
        return a.l < b.l || (a.l == b.l && a.r > b.r);
    }
} line[N];
bool becontain[N], contain[N];

int main() {
    int n, mx = -1, mi = 2147483647;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &line[i].l, &line[i].r);
        line[i].sit = i;
    }
    sort(line + 1, line + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (mx < line[i].r)
            mx = line[i].r;
        else
            becontain[line[i].sit] = true;
    }
    for (int i = n; i >= 1; i--) {
        if (mi > line[i].r)
            mi = line[i].r;
        else
            contain[line[i].sit] = true;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", contain[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", becontain[i]);
    return 0;
}