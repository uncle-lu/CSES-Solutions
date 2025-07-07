#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

const int N = 510;
struct node {
    int u, v, cap, flow;
};
std::vector<node> edges;
std::vector<int> G[N];
int n, m, F[N], front[N];
bool in_s[N];

void add_edge(int u, int v, int val) {
    edges.push_back((node){u, v, val, 0});
    edges.push_back((node){v, u, val, 0});
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
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v, 1);
    }
    int ans = EK(1, n);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        if (F[i] > 0)
            in_s[i] = true;
    for (int i = 1; i <= n; i++) {
        if (!in_s[i])
            continue;
        for (int e : G[i]) {
            if (in_s[edges[e].u] && !in_s[edges[e].v])
                printf("%d %d\n", edges[e].u, edges[e].v);
        }
    }
    return 0;
}