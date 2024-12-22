#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= 2;
        ans %= (int)1e9 + 7;
    }
    printf("%d", ans);
    return 0;
}