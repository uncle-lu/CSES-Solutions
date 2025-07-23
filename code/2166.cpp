#include <algorithm>
#include <cstdio>

const int N = 2e5 + 10;
using ll = long long int;
struct node {
    int l, r;
    ll val, tag;
} tree[N << 2];
int n, q;
ll line[N], sum[N];

void push_up(int x) {
    tree[x].val = std::max(tree[x << 1].val, tree[x << 1 | 1].val);
    return;
}

void make_tag(int x, ll v) {
    tree[x].val += v;
    tree[x].tag += v;
    return;
}

void push_down(int x) {
    if (!tree[x].tag)
        return;
    make_tag(x << 1, tree[x].tag);
    make_tag(x << 1 | 1, tree[x].tag);
    tree[x].tag = 0;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].val = sum[l];
        return;
    }
    int mid = (l + r) / 2;
    build_tree(x << 1, l, mid);
    build_tree(x << 1 | 1, mid + 1, r);
    push_up(x);
}

void update(int x, int cl, int cr, ll v) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        make_tag(x, v);
        return;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (cl <= mid)
        update(x << 1, cl, cr, v);
    if (cr > mid)
        update(x << 1 | 1, cl, cr, v);
    push_up(x);
    return;
}

ll query(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return tree[x].val;
    push_down(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (cr <= mid)
        return query(x << 1, cl, cr);
    else if (cl > mid)
        return query(x << 1 | 1, cl, cr);
    else
        return std::max(query(x << 1, cl, cr), query(x << 1 | 1, cl, cr));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &line[i]);
        sum[i] = sum[i - 1] + line[i];
    }
    build_tree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int model, x, y;
        scanf("%d %d %d", &model, &x, &y);
        if (model == 1) {
            update(1, x, n, y - line[x]);
            line[x] = y;
        } else {
            ll ans = query(1, x, y) - (x <= 1 ? 0 : query(1, x - 1, x - 1));
            if (ans < 0)
                ans = 0;
            printf("%lld\n", ans);
        }
    }
    return 0;
}