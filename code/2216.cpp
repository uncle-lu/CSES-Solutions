#include <cstdio>
const int N = 2e5 + 10;
int tong[N], n, temp;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        tong[temp] = i;
    }
    int cnt = 1;
    for (int i = 2; i <= n; i++)
        if (tong[i] < tong[i - 1]) {
            cnt++;
        }
    printf("%d", cnt);
    return 0;
}