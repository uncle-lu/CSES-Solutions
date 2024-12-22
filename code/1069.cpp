#include <cstdio>
#include <cstring>

const int N = 1e6 + 10;
char str[N];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    int s = 1, mx = 1;
    for (int i = 1; i < len; i++) {
        if (str[i] == str[i - 1])
            s++;
        else
            s = 1;
        if (s > mx)
            mx = s;
    }
    printf("%d", mx);
    return 0;
}