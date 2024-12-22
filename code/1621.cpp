#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
int n, line[N], cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    sort(line + 1, line + 1 + n);
    cnt = 1;
    for (int i = 2; i <= n; i++)
        if (line[i] != line[i - 1])
            cnt++;
    printf("%d", cnt);
    return 0;
}