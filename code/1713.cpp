#include <cmath>
#include <cstdio>
#include <vector>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, s, cnt = 0;
        scanf("%d", &n);
        s = sqrt(n);
        for (int i = 1; i <= s; i++) {
            if (n % i == 0) {
                cnt++;
                if (n / i != i)
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}