#include <cstdio>
 
const int N = 2e5 + 10;
int line[N];
 
int main() {
    int n;
    long long int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= n; i++)
        if (line[i] < line[i - 1]) {
            ans += (line[i - 1] - line[i]);
            line[i] = line[i - 1];
        }
    printf("%lld", ans);
    return 0;
}