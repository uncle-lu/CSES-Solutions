#include <cstdio>
#include <utility>
using namespace std;

pair<int, int> line[600010];
int n, ans, cnt;

void hanoi(int k, int a, int b, int c) {
    if (k < 1)
        return;
    hanoi(k - 1, a, c, b);
    cnt++;
    line[cnt] = make_pair(a, c);
    hanoi(k - 1, b, a, c);
    return;
}

int main() {
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d %d\n", line[i].first, line[i].second);
    return 0;
}