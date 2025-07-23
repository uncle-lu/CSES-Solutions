#include <cstdio>
#include <utility>
using namespace std;

const int N = 2e5 + 10;
using ll = long long int;
struct node {
    int l, r;
    ll sum, max, res; // sum 和, max 最大值, res 答案
} tree[N << 2];
int n, q, line[N];

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].res = 0;
        tree[x].max = tree[x].sum = line[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(x << 1, l, mid);
    build_tree(x << 1 | 1, mid + 1, r);
    tree[x].sum = tree[x].max = line[l];
    tree[x].res = 0;
    for (int i = l + 1; i <= r; i++) {
        tree[x].sum += line[i];
        if (tree[x].max <= line[i])
            tree[x].max = line[i];
        else
            tree[x].res += (tree[x].max - line[i]);
    }
    return;
}

// 当前节点是x, tree[x].l 前的最大值是 mx
pair<ll, ll> walk(int x, ll mx) {
    if (tree[x].l == tree[x].r) { // 区间长度为 1
        if (tree[x].max >= mx)
            return make_pair(0, tree[x].max);
        return make_pair(mx - tree[x].max, mx);
    }
    if (tree[x].max <= mx) // 整个区间都需要变成mx
        return make_pair(mx * (tree[x].r - tree[x].l + 1) - tree[x].sum, mx);
    if (tree[x << 1].max >= mx) // 左区间的最大值 比前面的mx要大
        return make_pair(walk(x << 1, mx).first + tree[x].res - tree[x << 1].res, tree[x].max);
    else // 右区间的最大值 比前面的mx要大
        return make_pair((tree[x << 1].r - tree[x << 1].l + 1) * mx - tree[x << 1].sum + walk(x << 1 | 1, mx).first,
                         tree[x].max);
}

// first 答案, second 范围内的最大值
pair<ll, ll> query(int x, int cl, int cr, ll mx) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        pair<ll, ll> temp = walk(x, mx);
        return temp;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (cr <= mid)
        return query(x << 1, cl, cr, mx);
    else if (cl > mid)
        return query(x << 1 | 1, cl, cr, mx);
    else {
        pair<ll, ll> res1 = query(x << 1, cl, cr, mx);
        pair<ll, ll> res2 = query(x << 1 | 1, cl, cr, res1.second);
        return make_pair(res1.first + res2.first, res2.second);
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(1, l, r, 0).first);
    }
    return 0;
}