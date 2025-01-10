#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 2e5 + 10;
struct node {
    int v, next;
} edge[N];
int head[N], cnt, n, size[N];

void add_edge(int x, int y) {
    edge[++cnt].v = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
    return;
}

void DFS(int x) {
    for (int i = head[x]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        DFS(v);
        size[x] += size[v] + 1;
    }
    return;
}

int main() {
    memset(head, -1, sizeof(head));
    int temp;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &temp);
        add_edge(temp, i);
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
        printf("%d ", size[i]);
    return 0;
}