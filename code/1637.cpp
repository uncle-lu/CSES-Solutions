#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
int F[N], n;

bool has(int x, int t) {
    while (x != 0) {
        if (x % 10 == t)
            return true;
        x /= 10;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    memset(F, 0x7f, sizeof(F));
    F[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 9; j++)
            if (has(i + j, j))
                F[i + j] = std::min(F[i + j], F[i] + 1);
    }
    printf("%d", F[n]);
    return 0;
}