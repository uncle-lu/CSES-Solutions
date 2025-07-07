#include <cstdio>

const int N = 2e5 + 10;
int n, q;
long long int line[N], sum[N];

int main() {
    scanf("%d %d" ,&n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &line[i]);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + line[i];
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }
    return 0;
}