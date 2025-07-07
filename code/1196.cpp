#include <cstdio>
#include <cstring>
#include <queue>
 
const int N = 2e5 + 10;
struct heap_node {
    int v;
    long long int d;
    friend bool operator<(const heap_node a, const heap_node b) {
        return a.d > b.d;
    }
};
struct node {
    int v, next;
    long long int val;
} edge[N];
int n, m, k, cnt, head[N], tot[N];
long long int dis[N];
 
void add_edge(int x, int y, long long int val) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    edge[cnt].val = val;
    head[x] = cnt;
    return;
}
 
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long int val;
        scanf("%d %d %lld", &u, &v, &val);
        add_edge(u, v, val);
    }
    memset(dis, 0x7f, sizeof(dis));
    std::priority_queue<heap_node> qu;
    qu.push((heap_node){1, 0});
    dis[1] = 0;
    while (!qu.empty()) {
        heap_node now = qu.top();
        qu.pop();
        tot[now.v]++;
        if (now.v == n) {
            printf("%lld ", now.d);
            if (tot[n] >= k)
                break;
        }
        if (tot[now.v] > k)
            continue;
        for (int i = head[now.v]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            qu.push((heap_node){v, now.d + edge[i].val});
        }
    }
    return 0;
}