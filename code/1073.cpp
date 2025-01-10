#include <cstdio>
#include <set>
using namespace std;

int main() {
    int n, temp;
    multiset<int> s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        auto x = s.upper_bound(temp);
        if (x != s.end())
            s.erase(x);
        s.insert(temp);
    }
    printf("%d", (int)s.size());
    return 0;
}