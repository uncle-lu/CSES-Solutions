#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
char str[N], ans[N];
int tong[30];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        tong[str[i] - 'A']++;
    int flag = 0, c = 0;
    for (int i = 0; i < 26; i++)
        if (tong[i] % 2) {
            flag++;
            c = i;
        }
    if (flag == 1)
        ans[(len - 1) / 2] = c + 'A';
    if (flag > 1) {
        printf("NO SOLUTION");
        return 0;
    }
    for (int i = 0, j = 0; i < 26; i++)
        while (tong[i] >= 2) {
            ans[j] = i + 'A';
            ans[len - j - 1] = i + 'A';
            tong[i] -= 2;
            j++;
        }
    printf("%s", ans);
    return 0;
}