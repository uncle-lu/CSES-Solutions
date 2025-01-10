#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    map<int, int> mp;
    int n, temp, cnt = 0, far = 1, mx = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (mp.find(temp) == mp.end())
            cnt++;
        else {
            if (mp[temp] < far)
                cnt++;
            else {
                far = mp[temp] + 1;
                cnt = i - far + 1;
            }
        }
        mp[temp] = i;
        mx = max(mx, cnt);
    }
    printf("%d", mx);
    return 0;
}