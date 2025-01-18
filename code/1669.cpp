#include <cstdio>
#include <cstring>

const int N = 1e5 + 10, M = 2e5 + 10;
struct node {
    int v, next;
} edge[2 * M];
int head[N], vis[N], front[N], line[N], cnt, n, m;
int flag;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!vis[v]) {
            vis[v] = vis[x] + 1;
            front[v] = x;
            DFS(v);
            if (flag)
                return;
        } else {
            if (vis[v] > vis[x] - 2)
                continue;
            int t = x;
            line[++flag] = v;
            while (t != v) {
                line[++flag] = t;
                t = front[t];
            }
            line[++flag] = v;
            return;
        }
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
        add_edge(v, u);
    }
    for (int i = 1; i <= n && !flag; i++) {
        vis[i] = 1;
        DFS(i);
    }
    if (!flag)
        printf("IMPOSSIBLE");
    else {
        printf("%d\n", flag);
        for (int i = 1; i <= flag; i++)
            printf("%d ", line[i]);
    }
    return 0;
}