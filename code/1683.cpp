#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[N * 2];
int cnt, scc_cnt, n, m, tot, top, sta[N], head[N], dfn[N], low[N], scc[N];
bool vis[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    vis[x] = true;
    sta[++top] = x;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[x] = std::min(low[x], low[v]);
        } else if (vis[v])
            low[x] = std::min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x]) {
        int v;
        scc_cnt++;
        do {
            v = sta[top--];
            scc[v] = scc_cnt;
            vis[v] = false;
        } while (v != x);
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    printf("%d\n", scc_cnt);
    for (int i = 1; i <= n; i++)
        printf("%d ", scc[i]);
    return 0;
}