#include <cstdio>

int main() {
    long long int n;
    scanf("%lld", &n);
    while (n != 1) {
        printf("%lld ", n);
        if (n & 1)
            n = n * 3 + 1;
        else
            n >>= 1;
    }
    printf("%lld ", n);
    return 0;
}