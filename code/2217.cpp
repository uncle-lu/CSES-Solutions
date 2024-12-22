#include <algorithm>
#include <cstdio>
const int N = 2e5 + 10;
int line[N], tong[N], n, m, cnt = 1;

void turn(int x, int y) {
    if (tong[line[x] - 1] <= tong[line[x]] && y < tong[line[x] - 1])
        cnt++;
    if (tong[line[x] - 1] > tong[line[x]] && y >= tong[line[x] - 1])
        cnt--;
    if (tong[line[x] + 1] >= tong[line[x]] && y > tong[line[x] + 1])
        cnt++;
    if (tong[line[x] + 1] < tong[line[x]] && y <= tong[line[x] + 1])
        cnt--;
    tong[line[x]] = y;
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        tong[line[i]] = i;
    }
    tong[n + 1] = n + 1;
    for (int i = 2; i <= n; i++)
        if (tong[i] < tong[i - 1])
            cnt++;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        turn(a, b);
        turn(b, a);
        std::swap(line[a], line[b]);
        printf("%d\n", cnt);
    }
    return 0;
}