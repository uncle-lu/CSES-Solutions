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
std::vector<int> line;
int F[N], front[N], n, m;
bool vis[N];

void add_edge(int u, int v, int val) {
    edges.push_back((node){u, v, val, 0});
    edges.push_back((node){v, u, 0, 0});
    int cnt = edges.size();
    G[v].push_back(cnt - 1);
    G[u].push_back(cnt - 2);
}

int EK(int start, int end) {
    int flow = 0;
    while (true) {
        memset(F, 0, sizeof(F));
        F[start] = 0x7f7f7f7f;
        std::queue<int> qu;
        qu.push(start);
        while (!qu.empty()) {
            int now = qu.front();
            qu.pop();
            for (int e : G[now]) {
                node &edge = edges[e];
                if (!F[edge.v] && edge.cap - edge.flow > 0) {
                    F[edge.v] = std::min(F[now], edge.cap - edge.flow);
                    front[edge.v] = e;
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

bool DFS(int x) {
    vis[x] = true;
    if (x == n)
        return true;
    for (int e : G[x]) {
        node &edge = edges[e];
        if (!vis[edge.v] && edge.flow > 0 && DFS(edge.v)) {
            edge.flow--;
            line.push_back(edge.v);
            return true;
        }
    }
    return false;
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
    for (int i = 1; i <= ans; i++) {
        memset(vis, false, sizeof(vis));
        line.clear();
        DFS(1);
        line.push_back(1);
        std::reverse(line.begin(), line.end());
        printf("%d\n", line.size());
        for (int one : line)
            printf("%d ", one);
        printf("\n");
    }
    return 0;
}