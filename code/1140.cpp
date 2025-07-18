#include <algorithm>
#include <cstdio>

const int N = 2e5 + 10;
struct node {
    int l, r, val;
    friend bool operator<(const node a, const node b) {
        return a.r < b.r || (a.r == b.r && a.l < b.l);
    }
} line[N];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {

    }
}