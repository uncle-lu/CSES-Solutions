#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct BIT {
    int size;
    std::vector<int> bit;
    BIT(int s) : size(s), bit(s + 1) {}
#define lowbit(x) (x & (-x))
    void update(int x, int val) {
        while (x <= size) {
            bit[x] += val;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int result = 0;
        while (x > 0) {
            result += bit[x];
            x -= lowbit(x);
        }
        return result;
    }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> line(n + 1);
    vector<int> ans(q + 1);
    vector<vector<pair<int, int>>> query(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &line[i]);
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        query[l].push_back(make_pair(r, i));
    }

    BIT bit(n);
    map<int, int> first_one;
    for (int i = n; i >= 1; i--) { // 枚举序列
        if (first_one.find(line[i]) != first_one.end())
            bit.update(first_one[line[i]], -1);
        first_one[line[i]] = i;
        bit.update(i, 1);
        for (auto curr : query[i])
            ans[curr.second] = bit.query(curr.first);
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}