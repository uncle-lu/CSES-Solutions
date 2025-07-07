#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[2 * N], reedge[2 * N];
int cnt, recnt, n, m, head[N], rehead[N];
bool vis[N], revis[N];

void add_edge(int x, int y, node *edge, int *head, int &cnt) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dfs(int x, int fa, node *edge, int *head, bool *vis) {
    vis[x] = true;
    for (int i = head[x]; ~i; i = edge[i].next)
        if (edge[i].v != fa && !vis[edge[i].v])
            dfs(edge[i].v, x, edge, head, vis);
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(rehead, -1, sizeof(rehead));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v, edge, head, cnt);
        add_edge(v, u, reedge, rehead, recnt);
    }
    dfs(1, 0, edge, head, vis);
    dfs(1, 0, reedge, rehead, revis);
    bool flag = true;
    for (int i = 2; i <= n; i++)
        if (!vis[i] || !revis[i]) {
            flag = false;
            printf("NO\n");
            if (!vis[i])
                printf("%d %d", 1, i);
            else
                printf("%d %d", i, 1);
            break;
        }
    if (flag)
        printf("YES");
    return 0;
}