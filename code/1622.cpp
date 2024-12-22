#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tong[30], len;
vector<string> ans;

void DFS(int x, string now) {
    if (x >= len) {
        ans.push_back(now);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (!tong[i])
            continue;
        tong[i]--;
        DFS(x + 1, now + (char)('a' + i));
        tong[i]++;
    }
    return;
}

int main() {
    string str;
    cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++)
        tong[str[i] - 'a']++;
    DFS(0, "");
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}