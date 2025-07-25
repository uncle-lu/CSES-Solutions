#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
vector<int>G[N];
int n, dis[N];

int BFS(int x) {
    memset(dis, 0, sizeof(dis));
    int mx = 0, sit = x;
    queue<int>qu;
    qu.push(x);
    dis[x] = 1;
    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for(int v : G[now]) {
            if(dis[v])  continue;
            dis[v] = dis[now] + 1;
            if(dis[v] > mx) {
                mx = dis[v];
                sit = v;
            }
            qu.push(v);
        }
    }
    return sit;
}

int main() {
    int u, v;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s1 = BFS(1);
    int s2 = BFS(s1);
    printf("%d", dis[s2] - 1);
    return 0;
}