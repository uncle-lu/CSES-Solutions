#include <cstdio>

const int N = 510, M = 250500;
const int Mod = 1e9 + 7;
int n;
long long int f[N][M + 10];

long long int _power(long long int x) {
    long long int ans = 1;
    long long int b = Mod - 2;
    while (b != 0) {
        if (b & 1)
            ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int target = n * (n + 1) / 4;
    if (n * (n + 1) / 2 % 2) {
        printf("0");
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            f[i][j] = f[i - 1][j]; // 不选第j个数
            if (j - i < 0)
                continue;
            f[i][j] = (f[i][j] + f[i - 1][j - i]) % Mod; // 选第j个数
        }
    }
    printf("%lld", f[n][target] * _power(2) % Mod);
    return 0;
}