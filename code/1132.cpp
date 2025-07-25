#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
vector<int> edge[N];
int n, F[2][N], G[N], c[N];

void DFS1(int x, int fa) {
    for (int v : edge[x]) {
        if (v == fa)
            continue;
        DFS1(v, x);
        if (F[1][v] + 1 > F[1][x]) {
            F[0][x] = F[1][x];
            F[1][x] = F[1][v] + 1;
            c[x] = v;
        } else if (F[1][v] + 1 > F[0][x])
            F[0][x] = F[1][v] + 1;
    }
    return;
}

void DFS2(int x, int fa) {
    G[x] = max(G[fa] + 1, F[c[fa] != x][fa] + 1);
    if (x == 1)
        G[x] = 0;
    for (int v : edge[x]) {
        if (v == fa)
            continue;
        DFS2(v, x);
    }
    return;
}

int main() {
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        edge[v].push_back(u);
        edge[u].push_back(v);
    }
    DFS1(1, 0);
    DFS2(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", max(G[i], F[1][i]));
    return 0;
}