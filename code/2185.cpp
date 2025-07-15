#include <cstdio>

using ll = long long int;
const ll INF = 1e18 + 10;
ll n, ans, line[30];
int k;

int main() {
    scanf("%lld %d", &n, &k);
    for (int i = 1; i <= k; i++)
        scanf("%lld", &line[i]);

    for (int now = 1; now <= (1 << k) - 1; now++) {
        bool flag = true;
        int t = 1, temp = now;
        long long int prod = 1, cnt = 0;
        while (temp) {
            if (temp & 1) {
                if (prod >= n / line[t] + 1) {
                    flag = false;
                    break;
                }
                prod = prod * line[t];
                cnt++;
            }
            temp >>= 1;
            t++;
        }
        if (flag)
            ans += (cnt % 2 ? 1 : -1) * n / prod;
    }
    printf("%lld", ans);
    return 0;
}