#include <algorithm>
#include <cstdio>

const int N = 2e5 + 10;
struct listnode {
    int val, front, next;
};
listnode line[N];
struct node {
    int val, sit;
} item[N];
int reitem[N], ansline[N], x, n, cnt;

void insert(int x, int val, int front, int next) {
    line[x].val = val;
    line[x].front = front;
    line[x].next = next;
    return;
}

int main() {
    scanf("%d %d", &x, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &item[i].val);
        item[i].sit = i;
    }
    std::sort(item + 1, item + 1 + n, [](node a, node b) { return a.val < b.val; });
    insert(0, 0, 0, 1);
    for (int i = 1; i <= n; i++) {
        reitem[item[i].sit] = i;
        insert(i, item[i].val, i - 1, i + 1);
    }
    insert(n + 1, x, n, n + 1);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
        ans = std::max(ans, line[i].val - line[i - 1].val);
    ansline[++cnt] = ans;
    for (int i = n; i > 1; i--) {
        int sit = reitem[i];
        ans = std::max(ans, line[line[sit].next].val - line[line[sit].front].val);
        line[line[sit].next].front = line[sit].front;
        line[line[sit].front].next = line[sit].next;
        ansline[++cnt] = ans;
    }
    for (int i = n; i >= 1; i--)
        printf("%d ", ansline[i]);
    return 0;
}