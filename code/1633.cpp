#include <cstdio>

const int N = 1e6 + 10;
long long int f[N];

int main() {
    int n;
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
                f[i] = (f[i] + f[i - j]) % (int)(1e9 + 7);

    printf("%lld", f[n]);
    return 0;
}