#include <cstdio>
#include <cstring>

const int N = 1e5 + 10, M = 2e5 + 10;
struct node {
    int v, next;
};
node edge[M * 2];
int head[N], color[N], n, m, cnt;
bool flag = false;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!color[v]) {
            color[v] = (color[x] == 1 ? 2 : 1);
            DFS(v);
        } else if (color[v] == color[x])
            flag = true;
        if (flag)
            return;
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
    for (int i = 1; i <= n && !flag; i++)
        if (!color[i]) {
            color[i] = 1;
            DFS(i);
        }
    if (flag)
        printf("IMPOSSIBLE");
    else {
        for (int i = 1; i <= n; i++)
            printf("%d ", color[i]);
    }
    return 0;
}