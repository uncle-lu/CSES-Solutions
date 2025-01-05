#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int N = 1010;
int n, m, cnt, f;
int x_turn[4] = {0, 0, 1, -1};
int y_turn[4] = {1, -1, 0, 0};
char ch[4] = {'R', 'L', 'D', 'U'};
char maps[N][N];
string ans;
bool vis[N][N];
struct node {
    int x, y;
    string str;
};

void BFS(int x, int y) {
    node now = (node){x, y, ""};
    queue<node> qu;
    qu.push(now);
    vis[x][y] = true;
    while (!qu.empty()) {
        now = qu.front();
        qu.pop();
        if (maps[now.x][now.y] == 'B') {
            f = 1;
            ans = now.str;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || maps[xx][yy] == '#' || vis[xx][yy])
                continue;
            vis[xx][yy] = true;
            qu.push((node){xx, yy, now.str + ch[i]});
        }
    }
    return;
}

int main() {
    freopen("test_input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> maps[i] + 1;
    for (int i = 1; i <= n && !f; i++)
        for (int j = 1; j <= m; j++)
            if (maps[i][j] == 'A') {
                BFS(i, j);
                break;
            }
    if (f)
        cout << "YES" << endl << ans.length() << endl << ans;
    else
        cout << "NO";
    return 0;
}