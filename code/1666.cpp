#include <cstdio>

const int N = 1e5 + 10;
struct node {
    int x, y;
} ans_line[N];
int father[N];

int find_father(int x) {
    return father[x] == x ? x : father[x] = find_father(father[x]);
}

void merge_father(int x, int y) {
    int fx = find_father(x), fy = find_father(y);
    if (fx != fy)
        father[fy] = fx;
    return;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        merge_father(x, y);
    }
    int target = find_father(1), ans = 0;
    for (int i = 2; i <= n; i++) {
        int fi = find_father(i);
        if (target != fi) {
            father[fi] = target;
            ans_line[++ans] = (node){fi, target};
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++)
        printf("%d %d\n", ans_line[i].x, ans_line[i].y);
    return 0;
}