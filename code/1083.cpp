#include <cstdio>

int main() {
    int n, temp;
    long long int sum = 0, ans = 0;
    scanf("%d", &n);
    sum = 1ll * (n + 1) * n / 2;
    for (int i = 1; i < n; i++) {
        scanf("%d", &temp);
        ans += temp;
    }
    ans = sum - ans;
    printf("%lld", ans);
    return 0;
}