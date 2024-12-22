#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;
int line[N], n;

int main() {
    long long int ans = -1e9 - 10, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        ans = max(ans, 1ll * line[i]);
    }
    for (int i = 1; i <= n; i++) {
        sum += line[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    printf("%lld", ans);
    return 0;
}