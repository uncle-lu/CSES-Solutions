#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
struct node {
    int v, next, val;
};
node edge[4 * N];
int head[N], n, m, cnt;
long long int dis[N];
bool vis[N];
struct qu_node {
    int v;
    long long int w;
    friend bool operator<(const qu_node a, const qu_node b) {
        return a.w > b.w;
    }
};

void add_edge(int x, int y, int val) {
    edge[++cnt].v = y;
    edge[cnt].val = val;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void dijkstra() {
    memset(dis, 0x7f, sizeof(dis));
    priority_queue<qu_node> qu;
    dis[1] = 0;
    qu.push((qu_node){1, 0});
    while (!qu.empty()) {
        qu_node now = qu.top();
        qu.pop();
        int x = now.v;
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[x] + edge[i].val) {
                dis[v] = dis[x] + edge[i].val;
                qu.push((qu_node){v, dis[v]});
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
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}