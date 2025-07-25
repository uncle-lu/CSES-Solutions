#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;

using ll = long long int;
vector<int> G[N];
int n, q, tot, dfn[N], redfn[N], top[N], c[N], sons[N], fa[N], line[N];

struct BIT {
    int size;
    vector<ll> bit;
    BIT(int s) : size(s), bit(s + 1) {
    }
#define lowbit(x) (x & (-x))
    ll query_one(int x) {
        ll result = 0;
        while (x > 0) {
            result += bit[x];
            x -= lowbit(x);
        }
        return result;
    }
    ll query(int l, int r) {
        return query_one(r) - query_one(l - 1);
    }
    void update(int x, ll val) {
        while (x <= size) {
            bit[x] += val;
            x += lowbit(x);
        }
        return;
    }
};

void DFS1(int x, int father) {
    sons[x] = 1;
    fa[x] = father;
    for (int v : G[x]) {
        if (v == father)
            continue;
        DFS1(v, x);
        sons[x] += sons[v];
    }
    return;
}

void DFS2(int x, int t, BIT &tree) { // t当前节点的重链链头
    dfn[++tot] = x;                  // DFS序 : 第tot次搜索到的元素是x
    tree.update(tot, line[x]);
    redfn[x] = tot; // redfn：x是第tot次搜索到的
    top[x] = t;
    int mxson = 0;
    for (int v : G[x]) {
        if (v == fa[x])
            continue;
        if (mxson < sons[v]) {
            c[x] = v;
            mxson = sons[v];
        }
    }
    if (c[x])
        DFS2(c[x], t, tree);
    for (int v : G[x]) {
        if (v == fa[x] || v == c[x])
            continue;
        DFS2(v, v, tree);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &q);
    BIT tree(n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS1(1, 0);
    DFS2(1, 1, tree);

    while (q--) {
        int model, s, x;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d", &s, &x);
            tree.update(redfn[s], x - line[s]);
            line[s] = x;
        } else if (model == 2) {
            scanf("%d", &s);
            printf("%lld\n", tree.query(redfn[s], redfn[s] + sons[s] - 1));
        }
    }
    return 0;
}