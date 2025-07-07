#include <cstdio>
#include <vector>
 
const int N = (1 << 16) - 1;
std::vector<int>G[N];
int n, top, ans[N];
bool vis[N];
 
void DFS(int x) {
    while(!G[x].empty()) {
        int v = G[x].back();
        G[x].pop_back();
        if(vis[v])continue;
        vis[v] = true;
        DFS(v);
    }
    ans[++top] = x;
}
 
int main() {
    scanf("%d", &n);
    for(int i = 0; i <= (1 << n) - 1; i++) {
        int temp = (i << 1) & ((1 << n) - 1);
        G[i].push_back(temp);
        G[i].push_back(temp ^ 1);
    }
    DFS(0);
    if(n == 1) 
        printf("01");
    else {
        for(int i = 3; i <= n; i++)
            printf("0");
        for(int i = top; i >= 1; i--)
            printf("%d", ans[i] & 1);
    }
    return 0;
}