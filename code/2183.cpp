#include <algorithm>
#include <cstdio>
const int N = 2e5;
int line[N], n;
long long int ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    std::sort(line + 1, line + 1 + n);
    ans = 1;
    for (int i = 0; i <= n && line[i] <= ans; i++)
        ans += line[i];
    printf("%lld\n", ans);
    return 0;
}