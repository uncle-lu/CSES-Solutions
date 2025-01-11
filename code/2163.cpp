#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

int main() {
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> t;
    int n, k, sit;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        t.insert(i);

    sit = k;
    while (!t.empty()) {
        sit %= t.size();
        auto x = t.find_by_order(sit);
        cout << *x << " ";
        t.erase(x);
        sit += k;
    }
    return 0;
}