#include <cmath>
#include <cstdio>
using namespace std;

int n, line[25];
long long int ans, sum, c;
bool vis[25];

void DFS(int x) {
    if (x > n) {
        if (abs(sum - c * 2) < ans)
            ans = abs(sum - c * 2);
        return;
    }
    c += line[x];
    DFS(x + 1);
    c -= line[x];
    DFS(x + 1);
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        sum += line[i];
    }
    ans = sum;
    DFS(1);

    printf("%lld", ans);
    return 0;
}