#include <cstdio>

void f(int x) {
    if (x == 1) {
        printf("0\n");
        return;
    }
    long long int ans = 1ll * (x * x - 1) * x * x / 2;
    ans -= 1ll * (x - 1) * (x - 2) * 4;
    printf("%lld\n", ans);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        f(i);
    return 0;
}