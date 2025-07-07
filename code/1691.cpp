#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
 
const int N = 1e5 + 10;
std::vector<std::pair<int, int>> G[N];
int n, m, top, deg[N], ans[2 * N];
bool vis[2 * N];
 
void DFS(int x) {
    while (!G[x].empty()) {
        auto now = G[x].back(); // G[x] 取最后一条边
        G[x].pop_back();        // G[x] 最后一条边 删除
        if (vis[now.second])    // 无向图
            continue;
        vis[now.second] = true; // 记录这条边走过了
        DFS(now.first);
    }
    ans[++top] = x;
}
 
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(std::make_pair(v, i)); // first 终点 second 边的编号
        G[v].push_back(std::make_pair(u, i));
        deg[u]++;
        deg[v]++;
    }
 
    for (int i = 1; i <= n; i++)
        if (deg[i] % 2) {
            printf("IMPOSSIBLE");
            return 0;
        }
 
    DFS(1);
 
    if (top != m + 1) {
        printf("IMPOSSIBLE");
        return 0;
    }
    for (int i = top; i >= 1; i--)
        printf("%d ", ans[i]);
    return 0;
}
