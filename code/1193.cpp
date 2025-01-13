#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int N = 1010;
int n, m, cnt, f, start_x, start_y, end_x, end_y;
int x_turn[4] = {0, 0, 1, -1};
int y_turn[4] = {1, -1, 0, 0};
int ans_turn[N][N];
char ch[4] = {'R', 'L', 'D', 'U'};
char maps[N][N], ans[N * N];
bool vis[N][N];
struct node {
    int x, y;
};

void BFS(int x, int y) {
    node now = (node){x, y};
    queue<node> qu;
    qu.push(now);
    vis[x][y] = true;
    while (!qu.empty()) {
        now = qu.front();
        qu.pop();
        if (maps[now.x][now.y] == 'B') {
            end_x = now.x;
            end_y = now.y;
            f = 1;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + x_turn[i], yy = now.y + y_turn[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || maps[xx][yy] == '#' || vis[xx][yy])
                continue;
            ans_turn[xx][yy] = i;
            vis[xx][yy] = true;
            qu.push((node){xx, yy});
        }
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("\n%s", maps[i] + 1);
    for (int i = 1; i <= n && !f; i++)
        for (int j = 1; j <= m; j++)
            if (maps[i][j] == 'A') {
                start_x = i;
                start_y = j;
                BFS(i, j);
                break;
            }
    if (!f) {
        printf("NO");
        return 0;
    } else
        printf("YES\n");
    int x = end_x, y = end_y, cnt = 0;
    do {
        int turn = ans_turn[x][y];
        ans[++cnt] = ch[turn];
        x = x + x_turn[turn ^ 1];
        y = y + y_turn[turn ^ 1];
    } while (!(x == start_x && y == start_y));
    printf("%d\n", cnt);
    for (int i = cnt; i >= 1; i--)
        printf("%c", ans[i]);
    return 0;
}
