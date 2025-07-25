#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
using ll = long long int;
vector<int> G[N];
int n, q, tot, line[N], dfn[N], redfn[N], sons[N], top[N], c[N], fa[N], dep[N];

struct BIT {
    int size;
    vector<ll> bit;
    BIT(int s) : size(s), bit(s + 1) {
    }
#define lowbit(x) (x & (-x))
    void update(int x, ll v) {
        while (x <= size) {
            bit[x] += v;
            x += lowbit(x);
        }
        return;
    }
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
};

void DFS1(int x, int father) {
    fa[x] = father;
    sons[x] = 1;
    dep[x] = dep[father] + 1;
    for (int v : G[x]) {
        if (v == father)
            continue;
        DFS1(v, x);
        sons[x] += sons[v];
    }
    return;
}

void DFS2(int x, int t, BIT &tree) {
    dfn[++tot] = x;
    redfn[x] = tot;
    top[x] = t;
    tree.update(tot, line[x]);
    int mxson = 0;
    for (int v : G[x]) {
        if (v == fa[x])
            continue;
        if (sons[v] > mxson) {
            mxson = sons[v];
            c[x] = v;
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

ll path(int x, int y, BIT &tree) {
    ll result = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        result += tree.query(redfn[top[x]], redfn[x]);
        x = fa[top[x]];
    }
    result += tree.query(min(redfn[x], redfn[y]), max(redfn[x], redfn[y]));
    return result;
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
        int model, s, x, y;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d", &s, &x);
            tree.update(redfn[s], x - line[s]);
            line[s] = x;
        } else {
            scanf("%d", &x);
            printf("%lld\n", path(1, x, tree));
        }
    }
    return 0;
}