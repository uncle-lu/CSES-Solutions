#include <algorithm>
#include <cstdio>

const int N = 1e6 + 10;
int tong[N], mx;

int main() {
    int n, temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        tong[temp]++;
        mx = std::max(mx, temp);
    }
    for (int i = mx; i >= 1; i--) {
        int cnt = 0;
        for (int j = 0; j <= mx; j += i)
            cnt += tong[j];
        if (cnt >= 2) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
