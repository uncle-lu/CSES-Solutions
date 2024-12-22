#include <cstdio>

int main() {
    int t, x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &x, &y);
        if ((x + y) % 3 || (x + y) / 3 > x || (x + y) / 3 > y) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}