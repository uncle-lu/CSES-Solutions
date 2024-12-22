#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int t, y, x, mx, mi, f;
    long long int ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &y, &x);
        if (x > y) {
            ans = 1ll * (x - 1) * (x - 1);
            if (x % 2)
                ans += x * 2 - 1 - y + 1;
            else
                ans += y;
        } else if (x < y) {
            ans = 1ll * (y - 1) * (y - 1);
            if (y % 2)
                ans += x;
            else
                ans += y * 2 - 1 - x + 1;
        } else {
            ans = 1ll * x * y - (x - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}