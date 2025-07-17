#include <algorithm>
#include <cstdio>
#include <cstring>

char str[2][5010];
int f[5010][5010];

int main() {
    scanf("%s\n%s", str[0] + 1, str[1] + 1);
    int len[2] = {(int)strlen(str[0] + 1), (int)strlen(str[1] + 1)};

    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= len[0]; i++)
        f[i][0] = i;
    for (int i = 1; i <= len[1]; i++)
        f[0][i] = i;

    for (int i = 1; i <= len[0]; i++) {
        for (int j = 1; j <= len[1]; j++) {
            if (str[0][i] == str[1][j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = std::min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + 1});
        }
    }
    printf("%d", f[len[0]][len[1]]);
    return 0;
}