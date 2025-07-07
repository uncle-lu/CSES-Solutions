#include <cstdio>
#include <cstring>

const int N = 30, M = (1 << 21) + 10;
const int mod = 1e9 + 7;
struct node {
    int v, next;
} edge[N * N + 10];
int n, m, cnt, head[N];
int F[M][N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

bool check(int target, int x) {
    return (target & (1 << (x - 1))) != 0;
}

int DFS(int target, int x) {
    if (~F[target][x])
        return F[target][x];
    int ans = 0;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (check(target, v)) {
            ans += DFS(target ^ (1 << (x - 1)), v);
            ans %= mod;
        }
    }
    return F[target][x] = ans;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(F, -1, sizeof(F));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v)
            continue;
        add_edge(v, u);
    }
    F[1][1] = 1;
    for (int i = 2; i <= n; i++)
        F[(1 << (i - 1))][i] = 0;
    printf("%d", DFS((1 << n) - 1, n) % mod);
    return 0;
}