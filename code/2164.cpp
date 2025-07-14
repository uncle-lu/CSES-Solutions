#include <cstdio>

int DFS(int n, int m) {
    if (n == 1)
        return 1;
    if (n % 2 == 0) {
        if (m * 2 <= n)
            return m * 2;
        else
            return DFS(n / 2, m - n / 2) * 2 - 1;
    }
    if (n % 2 == 1) {
        if (m * 2 <= n)
            return m * 2;
        else if (m * 2 == n + 1)
            return 1;
        else
            return DFS(n / 2, m - (n + 1) / 2) * 2 + 1;
    }
    return 0;
}

int main() {
    int n, m, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", DFS(n, m));
    }
    return 0;
}