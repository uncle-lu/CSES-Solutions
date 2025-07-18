#include <algorithm>
#include <cstdio>

const int N = 110, M = 100010;
int line[N], ans[M], n, cnt;
bool f[100010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &line[i]);
    std::sort(line, line + n);
    f[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = 100009 - line[i]; j >= 0; j--)
            f[j + line[i]] |= f[j];
    for (int i = 1; i <= 100010; i++)
        if (f[i])
            ans[++cnt] = i;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d ", ans[i]);
    return 0;
}