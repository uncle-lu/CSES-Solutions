#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int t, op;
    friend bool operator<(const node a, const node b) {
        return a.t < b.t || (a.t == b.t && a.op < b.op);
    }
};
node line[2 * N];

int main() {
    int n, a, b, cnt = 0, now = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        line[++cnt] = (node){a, 1};
        line[++cnt] = (node){b, -1};
    }
    sort(line + 1, line + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        now += line[i].op;
        if (now > ans)
            ans = now;
    }
    printf("%d", ans);
    return 0;
}