#include <cstdio>
#include <cstring>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[2 * N];
int n, m, cnt, top, ans, head[N], sta[N], line[N];
bool flag, vis[N], in[N];

void add_edge(int u, int v) {
    edge[++cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
    return;
}

void DFS(int x) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v] && !in[v])
            continue;
        if (vis[v]) {
            flag = true;
            line[++ans] = v;
            while (sta[top] != v) {
                line[++ans] = sta[top];
                top--;
            }
            line[++ans] = v;
            return;
        } else {
            vis[v] = in[v] = true;
            sta[++top] = v;
            DFS(v);
            top--;
            in[v] = false;
            if (flag)
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
    }
    for (int i = 1; i <= n && !flag; i++) {
        if (vis[i])
            continue;
        memset(in, false, sizeof(in));
        top = 0;
        sta[++top] = i;
        DFS(i);
    }
    if (!flag) {
        printf("IMPOSSIBLE");
    } else {
        printf("%d\n", ans);
        for (int i = ans; i >= 1; i--)
            printf("%d ", line[i]);
    }
    return 0;
}