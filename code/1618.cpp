#include <cstdio>

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    while (n != 0) {
        n /= 5;
        ans += n;
    }
    printf("%d", ans);
    return 0;
}