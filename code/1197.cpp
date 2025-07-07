#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
 
const int N = 5010;
struct node {
    int v, next;
    long long int val;
};
node edge[N];
int n, m, cnt, flag, head[N], tot[N], front[N];
long long int dis[N];
bool vis[N];
 
void add_edge(int x, int y, long long int val) {
    edge[++cnt].next = head[x];
    edge[cnt].val = val;
    edge[cnt].v = y;
    head[x] = cnt;
    return;
}
 
void spfa(int x) {
    memset(dis, 0x7f, sizeof(dis));
    std::queue<int> qu;
    qu.push(x);
    dis[x] = 0;
    vis[x] = true;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        vis[now] = false;
        tot[now]++;
        if (tot[now] > 2 * n) {
            // front[x] = now;
            flag = now;
            break;
        }
        for (int i = head[now]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[now] + edge[i].val < dis[v]) {
                dis[v] = dis[now] + edge[i].val;
                if (!vis[v]) {
                    vis[v] = true;
                    qu.push(v);
                    front[v] = now;
                }
            }
        }
    }
    vis[x] = false;
    return;
}
 
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long int val;
        scanf("%d %d %lld", &u, &v, &val);
        add_edge(u, v, val);
    }
    for (int i = 1; i <= n && !flag; i++)
        if (!tot[i])
            spfa(i);
    if (!flag)
        printf("NO");
    else {
        std::vector<int> ans;
        for(int i = 0; i < n; i++)
            flag = front[flag];
        ans.push_back(flag);
        for (int i = front[flag]; i != flag; i = front[i])
            ans.push_back(i);
        ans.push_back(flag);
        printf("YES\n");
        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%d ", ans[i]);
    }
    return 0;
}