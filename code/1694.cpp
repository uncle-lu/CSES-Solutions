#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int M = 1e3 + 10, N = 510;
struct node {
    int u, v, next, val;
};
node edge[M * 2];
int cnt = -1, n, m, head[N], front[N];
long long F[N];

void add_edge(int u, int v, int val) {
    edge[++cnt].v = v;
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].val = val;
    head[u] = cnt;
}

long long EK() {
    long long ans = 0;
    while (true) {
        memset(F, 0, sizeof(F));
        std::queue<int> qu;
        F[1] = 0x7f7f7f7f;
        qu.push(1);
        while (!qu.empty()) {
            int now = qu.front();
            qu.pop();
            for (int i = head[now]; ~i; i = edge[i].next) {
                int v = edge[i].v;
                if (!F[v] && edge[i].val > 0) {
                    front[v] = i;
                    F[v] = std::min(F[now], 1LL * edge[i].val);
                    qu.push(v);
                }
            }
            if (F[n])
                break;
        }
        if (!F[n])
            break;
        for (int curr = n; curr != 1; curr = edge[front[curr]].u) {
            edge[front[curr]].val -= F[n];
            edge[front[curr] ^ 1].val += F[n];
        }
        ans += F[n];
    }
    return ans;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, val;
        scanf("%d %d %d", &u, &v, &val);
        add_edge(u, v, val);
        add_edge(v, u, 0);
    }
    printf("%lld", EK());
    return 0;
}
