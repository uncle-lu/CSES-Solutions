#include <cstdio>
#include <vector>

const int N = 1e5 + 10;
int n, m, top, in[N], out[N], ans[2 * N];
std::vector<int> G[N];

void DFS(int x) {
    while (!G[x].empty()) {
        int now = G[x].back();
        G[x].pop_back();
        DFS(now);
    }
    ans[++top] = x;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    bool flag = false;
    for (int i = 2; i < n && !flag; i++)
        if (in[i] != out[i])
            flag = true;
    flag |= (in[1] + 1 != out[1]);
    flag |= (in[n] - 1 != out[n]);
    if (flag) {
        printf("IMPOSSIBLE");
        return 0;
    }
    DFS(1);
    if (top != m + 1)
        printf("IMPOSSIBLE");
    else {
        for (int i = top; i >= 1; i--)
            printf("%d ", ans[i]);
    }
    return 0;
}