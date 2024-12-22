#include <algorithm>
#include <cstdio>

const int N = 1010;
int h[N], s[N], F[100010];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++)
        for (int j = x; j >= h[i]; j--)
            F[j] = std::max(F[j], F[j - h[i]] + s[i]);
    printf("%d", F[x]);
    return 0;
}