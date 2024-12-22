#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10;
struct node {
    int val, sit;
    friend bool operator<(const node a, const node b) {
        return a.val < b.val;
    }
};
node line[N];
int n, x;

int search(int x) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (line[mid].val < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &line[i].val);
        line[i].sit = i;
    }
    sort(line + 1, line + 1 + n);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        int temp = search(x - line[i].val);
        if (line[temp].val == x - line[i].val && line[i].sit != line[temp].sit) {
            printf("%d %d", line[i].sit, line[temp].sit);
            flag = true;
            break;
        }
    }
    if (!flag)
        printf("IMPOSSIBLE");
    return 0;
}