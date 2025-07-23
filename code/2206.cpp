#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

using ll = long long int;
const int N = 2e5 + 10;
struct node {
    int l, r;
    ll val1, val2;
} tree[N << 2];
int line[N], n, q;

void push_up(int x) {
    tree[x].val1 = std::min(tree[x << 1].val1, tree[x << 1 | 1].val1);
    tree[x].val2 = std::min(tree[x << 1].val2, tree[x << 1 | 1].val2);
    return;
}

void make_tag(int x, ll v) {
    tree[x].val1 = v - tree[x].l;
    tree[x].val2 = v + tree[x].l;
    return;
}

void build_tree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].val1 = line[l] - l;
        tree[x].val2 = line[l] + l;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(x << 1, l, mid);
    build_tree(x << 1 | 1, mid + 1, r);
    push_up(x);
}

void update(int x, int cl, int cr, ll v) {
    if (tree[x].l >= cl && tree[x].r <= cr) {
        make_tag(x, v);
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (cl <= mid)
        update(x << 1, cl, cr, v);
    if (cr > mid)
        update(x << 1 | 1, cl, cr, v);
    push_up(x);
    return;
}

template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &lhs, const std::pair<T1, T2> &rhs) {
    return {std::min(lhs.first, rhs.first), std::min(lhs.second, rhs.second)};
}

pair<ll, ll> query(int x, int cl, int cr) {
    if (tree[x].l >= cl && tree[x].r <= cr)
        return make_pair(tree[x].val1, tree[x].val2);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (cr <= mid)
        return query(x << 1, cl, cr);
    else if (cl > mid)
        return query(x << 1 | 1, cl, cr);
    pair<ll, ll> temp(1e18, 1e18);
    temp = temp + query(x << 1, cl, cr);
    temp = temp + query(x << 1 | 1, cl, cr);
    return temp;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    build_tree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int model, x, y;
        scanf("%d", &model);
        if (model == 1) {
            scanf("%d %d", &x, &y);
            update(1, x, x, y);
        } else {
            scanf("%d", &x);
            printf("%lld\n", std::min(query(1, 1, x).first + x, query(1, x, n).second - x));
        }
    }
    return 0;
}