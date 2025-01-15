#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    map<int, int>mp;
    int n, temp, mx = 0;
    scanf("%d", &n);
    for(int r = 1, l = 1; r <= n; r++) {
        scanf("%d", &temp);
        if(mp.find(temp) != mp.end() && mp[temp] >= l)
            l = mp[temp] + 1;
        mp[temp] = r;
        mx = max(mx, r - l + 1);
    }
    printf("%d", mx);
    return 0;
}