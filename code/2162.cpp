#include <cstdio>

const int N = 2e5 + 10;
struct node {
    int next, val;
} line[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        line[i] = (node){i + 1, i};
    line[n].next = 1;
    int cnt = n, sit = 1;
    while (cnt--) {
        printf("%d ", line[line[sit].next].val);
        line[sit].next = line[line[sit].next].next;
        sit = line[sit].next;
    }
    return 0;
}