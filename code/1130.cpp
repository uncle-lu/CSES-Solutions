#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

using ll = long long int;
const int N = 2e5 + 10;
vector<int> G[N];
int n;
ll F[2][N];

void DFS(int x, int fa) {
    F[1][x] = -1e18;
    for (int v : G[x]) {
        if (v == fa)
            continue;
        DFS(v, x);
        F[0][x] += max(F[1][v], F[0][v]);
        ll temp = min(F[0][v] - F[1][v], 0LL);
        F[1][x] = max(F[1][x], temp);
    }
    F[1][x] += F[0][x];
    F[1][x]++;
    return;
}

int main() {
    int u, v;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);
    printf("%lld", max(F[1][1], F[0][1]));
    return 0;
}