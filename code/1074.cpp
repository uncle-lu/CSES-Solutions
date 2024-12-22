#include <algorithm>
#include <cstdio>
const int N = 2e5;
int line[N];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    std::sort(line + 1, line + 1 + n);
    long long sum = 0, target = line[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
        sum += std::abs(line[i] - target);
    printf("%lld", sum);
    return 0;
}