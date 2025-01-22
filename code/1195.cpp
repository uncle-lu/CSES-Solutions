#include <cstdio>
#include <cstring>
#include <queue>

const int N = 1e5 + 10, M = 2e5 + 10;
struct node {
    int v, next, val;
} edge[M];
struct heapnode {
    int v, div;
    long long int w;
    friend bool operator<(const heapnode a, const heapnode b) {
        return a.w > b.w;
    }
};
int head[N], cnt, n, m;
long long int d[3][N];
bool vis[3][N];

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dijkstra(int start) {
    memset(d, 0x7f, sizeof(d));
    d[0][start] = 0;
    std::priority_queue<heapnode> qu;
    qu.push((heapnode){start, 0, 0});
    while (!qu.empty()) {
        heapnode now = qu.top();
        qu.pop();
        if (vis[now.div][now.v])
            continue;
        vis[now.div][now.v] = true;
        for (int i = head[now.v]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (d[now.div][v] > d[now.div][now.v] + edge[i].val) {
                d[now.div][v] = d[now.div][now.v] + edge[i].val;
                qu.push((heapnode){v, now.div, d[now.div][v]});
            }
            if (now.div != 1 && d[now.div + 1][v] > d[now.div][now.v] + edge[i].val / 2) {
                d[now.div + 1][v] = d[now.div][now.v] + edge[i].val / 2;
                qu.push((heapnode){v, now.div + 1, d[now.div + 1][v]});
            }
        }
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
    }
    dijkstra(1);
    printf("%lld", d[0][n] < d[1][n] ? d[0][n] : d[1][n]);
    return 0;
}