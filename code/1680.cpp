#include <cstdio>
#include <cstring>
#include <queue>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[N * 2];
int n, m, cnt, head[N], dis[N], in[N], front[N];
bool vis[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x) {
    vis[x] = true;
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v])
            continue;
        DFS(v);
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
        in[v]++;
    }
    DFS(1);
    if (!vis[n]) {
        printf("IMPOSSIBLE");
        return 0;
    }
    std::queue<int> qu;
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            qu.push(i);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            in[v]--;
            if (dis[now] != -1 && dis[v] < dis[now] + 1) {
                dis[v] = dis[now] + 1;
                front[v] = now;
            }
            if (!in[v])
                qu.push(v);
        }
    }
    std::vector<int> ans;
    for (int i = n; i != 1; i = front[i])
        ans.push_back(i);
    ans.push_back(1);
    printf("%d\n", (int)ans.size());
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%d ", ans[i]);
    return 0;
}