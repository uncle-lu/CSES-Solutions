#include <cstdio>
#include <cstring>

const int N = 2e5 + 10;
int n, cnt, line[N], f[N];

int _find(int x) {
    int l = 1, r = cnt + 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (f[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    memset(f, 0x7f, sizeof(f));
    f[++cnt] = line[1];
    for (int i = 2; i <= n; i++) {
        int sit = _find(line[i]);
        if (sit == cnt + 1)
            f[++cnt] = line[i];
        else
            f[sit] = line[i];
    }
    printf("%d", cnt);
    return 0;
}