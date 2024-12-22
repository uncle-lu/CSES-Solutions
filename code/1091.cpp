#include <cstdio>
#include <set>
using namespace std;

int main() {
    multiset<int, greater<int>> h;
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        h.insert(temp);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &temp);
        if (h.lower_bound(temp) == h.end())
            printf("-1\n");
        else {
            printf("%d\n", *h.lower_bound(temp));
            h.erase(h.lower_bound(temp));
        }
    }
    return 0;
}