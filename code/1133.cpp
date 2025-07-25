#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
vector<int> edge[N];
int n;
long long int F[N], G[N], s[N];

void DFS1(int x, int fa) {
    s[x] = 1;
    for (int v : edge[x]) {
        if (v == fa)
            continue;
        DFS1(v, x);
        F[x] += (F[v] + s[v]);
        s[x] += s[v];
    }
    G[x] = F[x];
    return;
}

void DFS2(int x, int fa) {
    if (x != 1)
        G[x] = G[fa] - 2 * s[x] + n;
    for (int v : edge[x])
        if (v != fa)
            DFS2(v, x);
    return;
}

int main() {
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    DFS1(1, 0);
    DFS2(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", G[i]);
    return 0;
}