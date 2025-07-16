#include <cstdio>

using ll = long long int;
const int N = 1e6 + 10;
int n, tong[N];
ll f[N];

int main() {
    int temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        tong[temp]++;
    }
    for (int i = 1e6; i >= 1; i--) { // 枚举最大公约数
        ll cnt = 0, sum = 0;
        for (int j = i; j < 1e6; j += i) { // 枚举 i 的倍数
            cnt += tong[j];
            sum += f[j]; // 前面的状态用了后面的状态 i => 4 j => 2*4, 3*4, 4*4, ... <1e6
        }
        f[i] = (cnt * (cnt - 1) / 2) - sum;
    }
    printf("%lld", f[1]);
    return 0;
}