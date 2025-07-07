#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

const int N = 1e4 + 10;
struct node {
    int u, v, cap, flow;
};
std::vector<node> edges;
std::vector<int> G[N];
int n, m, k, F[N], front[N];
bool in_s[N];

void add_edge(int u, int v, int val) {
    edges.push_back((node){u, v, val, 0});
    edges.push_back((node){v, u, 0, 0});
    int cnt = edges.size();
    G[u].push_back(cnt - 2);
    G[v].push_back(cnt - 1);
    return;
}

int EK(int start, int end) {
    int flow = 0;
    while (true) {
        memset(F, 0, sizeof(F));
        std::queue<int> qu;
        qu.push(start);
        F[start] = 0x7f7f7f7f;
        while (!qu.empty()) {
            int now = qu.front();
            qu.pop();
            for (auto e : G[now]) {
                node edge = edges[e];
                if (!F[edge.v] && edge.cap > edge.flow) {
                    front[edge.v] = e;
                    F[edge.v] = std::min(F[now], edge.cap - edge.flow);
                    qu.push(edge.v);
                }
            }
            if (F[end])
                break;
        }
        if (!F[end])
            break;
        for (int curr = end; curr != start; curr = edges[front[curr]].u) {
            edges[front[curr]].flow += F[end];
            edges[front[curr] ^ 1].flow -= F[end];
        }
        flow += F[end];
    }
    return flow;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, n + v, 1);
    }
    for (int i = 1; i <= n; i++)
        add_edge(0, i, 1);
    for (int i = 1; i <= m; i++)
        add_edge(i + n, n + m + 1, 1);
    int ans = EK(0, n + m + 1);
    printf("%d\n", ans);
    for (node edge : edges) {
        if (edge.u == 0 || edge.u > n || edge.v == n + m + 1 || edge.cap == 0 || edge.flow <= 0)
            continue;
        printf("%d %d\n", edge.u, edge.v - n);
    }
    return 0;
}