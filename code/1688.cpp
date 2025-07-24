#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
vector<int> G[N];
int n, q, d[N][33], dep[N];

void DFS(int x, int depth) {
    dep[x] = depth;
    for (int v : G[x])
        DFS(v, depth + 1);
    return;
}

int lca(int x, int y) {
    if (dep[x] > dep[y])
        swap(x, y);
    for (int i = 30; i >= 0; i--)
        if (dep[x] <= dep[d[y][i]])
            y = d[y][i];
    if (x == y)
        return x;
    for (int i = 30; i >= 0; i--)
        if (d[x][i] != d[y][i]) {
            x = d[x][i];
            y = d[y][i];
        }
    return d[x][0];
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &d[i][0]);
        G[d[i][0]].push_back(i);
    }

    d[1][0] = 1;
    DFS(1, 0);
    for (int i = 1; i <= 30; i++)
        for (int x = 1; x <= n; x++)
            d[x][i] = d[d[x][i - 1]][i - 1];

    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}