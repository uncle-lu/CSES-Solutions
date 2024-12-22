#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
int a[N], b[N];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int curr1 = 1, curr2 = 1, ans = 0;
    while (curr1 <= n && curr2 <= m) {
        if (abs(a[curr1] - b[curr2]) <= k) {
            ans++;
            curr1++;
            curr2++;
        } else if (a[curr1] < b[curr2]) {
            curr1++;
        } else {
            curr2++;
        }
    }
    printf("%d", ans);
    return 0;
}