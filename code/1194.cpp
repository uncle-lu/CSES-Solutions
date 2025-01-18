#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int ti[N][N], front[N][N], n, m, master_cnt, ans_cnt;
char maps[N][N], ans[N * N];
bool vis[N][N];
int x_turn[4] = {1, -1, 0, 0};
int y_turn[4] = {0, 0, 1, -1};
char ch[4] = {'D', 'U', 'R', 'L'};
pair<int, int> master[N * N], start, End;

void BFS() {
    queue<pair<int, int>> qu;
    for (int i = 1; i <= master_cnt; i++) {
        qu.push(master[i]);
        ti[master[i].first][master[i].second] = 0;
        vis[master[i].first][master[i].second] = true;
    }
    while (!qu.empty()) {
        pair<int, int> now = qu.front();
        qu.pop();
        vis[now.first][now.second] = false;
        for (int i = 0; i < 4; i++) {
            int xx = now.first + x_turn[i], yy = now.second + y_turn[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || maps[xx][yy] == '#' ||
                ti[xx][yy] < ti[now.first][now.second] + 1 || vis[xx][yy])
                continue;
            ti[xx][yy] = ti[now.first][now.second] + 1;
            qu.push(make_pair(xx, yy));
            vis[xx][yy] = true;
        }
    }
    return;
}

bool DFS(pair<int, int> s, int t) {
    if (s.first == 1 || s.first == n || s.second == 1 || s.second == m) {
        End = s;
        return true;
    }
    for (int i = 0; i < 4; i++) {
        int xx = s.first + x_turn[i], yy = s.second + y_turn[i];
        if (maps[xx][yy] == '#' || ti[xx][yy] <= t + 1 || front[xx][yy] != -1)
            continue;
        front[xx][yy] = i;
        if (DFS(make_pair(xx, yy), t + 1))
            return true;
        front[xx][yy] = -1;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", maps[i] + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (maps[i][j] == 'M')
                master[++master_cnt] = make_pair(i, j);
            else if (maps[i][j] == 'A')
                start = make_pair(i, j);

    memset(ti, 0x7f, sizeof(ti));
    BFS();

    memset(front, -1, sizeof(front));
    if (DFS(start, 0)) {
        printf("YES\n");
        int x = End.first, y = End.second;
        while (maps[x][y] != 'A') {
            int turn = front[x][y];
            ans[++ans_cnt] = ch[turn];
            x = x + x_turn[turn ^ 1];
            y = y + y_turn[turn ^ 1];
        }
        reverse(ans + 1, ans + ans_cnt + 1);
        printf("%d\n", ans_cnt);
        for (int i = 1; i <= ans_cnt; i++)
            printf("%c", ans[i]);
    } else {
        printf("NO");
    }
    return 0;
}