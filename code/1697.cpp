#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

const int N = 1e5 + 10;
struct node {
    int v, next;
} edge[2 * N];
int n, m, cnt, head[N], in[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
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
    std::queue<int> qu;
    std::vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            qu.push(i);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        ans.push_back(now);
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            in[v]--;
            if (!in[v])
                qu.push(v);
        }
    }
    if (ans.size() != n)
        printf("IMPOSSIBLE");
    else {
        for (auto i : ans)
            printf("%d ", i);
    }
    return 0;
}