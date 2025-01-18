#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2510, M = 5010;
int n, m;
struct node {
    int v, next;
} edge[M], redge[M];
struct node2 {
    int u, v, val;
} line[M];
int head[N], rehead[N], cnt, recnt;
long long int d[N];
bool vis[N], revis[N];

void add_edge(int u, int v, int val, node *e, int *h, int &c) {
    e[++c].v = v;
    e[c].next = h[u];
    h[u] = c;
    return;
}

void DFS(int x, node *e, int *h, bool *v) {
    v[x] = true;
    for (int i = h[x]; ~i; i = e[i].next)
        if (!v[e[i].v])
            DFS(e[i].v, e, h, v);
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(rehead, -1, sizeof(rehead));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val, edge, head, cnt);
        add_edge(v, u, val, redge, rehead, recnt);
        line[i] = (node2){u, v, val};
    }

    DFS(1, edge, head, vis);
    DFS(n, redge, rehead, revis);

    for (int i = 1; i <= n; i++)
        d[i] = -1e18;
    d[1] = 0;
    bool flag = true;
    for (int i = 1; i <= n && flag; i++) {
        flag = false;
        for (int j = 1; j <= m; j++)
            if (d[line[j].v] < d[line[j].u] + line[j].val) {
                d[line[j].v] = d[line[j].u] + line[j].val;
                flag = true;

                if (i >= n && vis[line[j].v] && revis[line[j].v]) {
                    puts("-1");
                    return 0;
                }
            }
    }
    printf("%lld", d[n]);
    return 0;
}