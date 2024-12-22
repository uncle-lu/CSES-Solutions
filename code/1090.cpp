#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
int line[N];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    sort(line + 1, line + 1 + n);
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        if (line[l] + line[r] <= x)
            l++;
        ans++;
        r--;
    }
    printf("%d", ans);
    return 0;
}