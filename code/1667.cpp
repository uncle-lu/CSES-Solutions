#include <cstdio>
#include <cstring>
#include <queue>

const int N = 1e5 + 10, M = 2e5 + 10;
struct node {
    int v, next;
};
node edge[M * 2];
int head[N], d[N], line[N], cnt, n, m;

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void bfs(int start) {
    std::queue<int> qu;
    d[1] = 1;
    qu.push(1);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[v])
                continue;
            d[v] = now;
            qu.push(v);
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
    bfs(1);
    if (!d[n]) {
        printf("IMPOSSIBLE");
        return 0;
    }
    int ans = 0, sit = n;
    while (sit != 1) {
        line[++ans] = sit;
        sit = d[sit];
    }
    printf("%d\n1 ", ans + 1);
    for (int i = ans; i >= 1; i--)
        printf("%d ", line[i]);
    return 0;
}