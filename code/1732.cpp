#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
char str[N], target[N];
int targetlen, len, cnt, ans, next[N], f[N];

void make_next() {
    next[1] = 0;
    for (int i = 2, j = 0; i <= targetlen; i++) {
        while (j > 0 && target[i] != target[j + 1])
            j = next[j];
        if (target[i] == target[j + 1])
            j++;
        next[i] = j;
    }
    return;
}

void make_f() {
    for (int i = 1, j = 0; i <= len; i++) {
        while (j > 0 && (j == targetlen || str[i] != target[j]))
            j = next[j];
        if (str[i] == target[j + 1])
            j++;
        f[i] = j;
        if (f[i] == targetlen)
            ans++;
    }
    return;
}

int main() {
    scanf("%s", str + 1);
    scanf("%s", target + 1);
    targetlen = strlen(target + 1);
    len = strlen(str + 1);
    make_next();
    make_f();
    printf("%d", ans);
    return 0;
}