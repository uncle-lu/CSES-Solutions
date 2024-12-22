#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if ((1LL * (1 + n) * n / 2) % 2) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    if (n % 2) {
        printf("%d\n1 2 ", n / 2 + 1);
        for (int i = 1; i <= (n - 3) / 2; i += 2)
            printf("%d %d ", i + 3, (n - 3) - i + 1 + 3);
        printf("\n%d\n3 ", n / 2);
        for (int i = 2; i <= (n - 3) / 2; i += 2)
            printf("%d %d ", i + 3, (n - 3) - i + 1 + 3);
    } else {
        printf("%d\n", n / 2);
        for (int i = 1; i <= n / 2; i += 2) {
            printf("%d %d ", i, n - i + 1);
        }
        printf("\n%d\n", n / 2);
        for (int i = 2; i <= n / 2; i += 2) {
            printf("%d %d ", i, n - i + 1);
        }
    }
    return 0;
}