#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int l, r;
    friend bool operator<(const node a, const node b) {
        return a.r < b.r;
    }
};
node line[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &line[i].l, &line[i].r);
    sort(line + 1, line + 1 + n);
    int cnt = 0, lastr = 0;
    for (int i = 1; i <= n; i++)
        if (line[i].l >= lastr) {
            lastr = line[i].r;
            cnt++;
        }
    printf("%d", cnt);
    return 0;
}