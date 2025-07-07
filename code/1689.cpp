#include <algorithm>
#include <cstdio>
#include <vector>

struct node {
    int x, y, cnt;
    friend bool operator<(const node a, const node b) {
        return a.cnt < b.cnt;
    }
};
int x_turn[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_turn[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int vis[10][10];

bool DFS(int x, int y, int step) {
    if (step == 64) {
        return true;
    }
    std::vector<node> line;
    for (int i = 0; i < 8; i++) {
        int xx = x + x_turn[i], yy = y + y_turn[i];
        if (xx < 1 || xx > 8 || yy < 1 || yy > 8 || vis[xx][yy])
            continue;
        node now = (node){xx, yy, 0};
        for (int j = 0; j < 8; j++) {
            int nowx = now.x + x_turn[j], nowy = now.y + y_turn[j];
            if (nowx < 1 || nowx > 8 || nowy < 1 || nowy > 8 || vis[nowx][nowy])
                continue;
            now.cnt++;
        }
        line.push_back(now);
    }
    std::sort(line.begin(), line.end());
    for (node now : line) {
        vis[now.x][now.y] = step + 1;
        if (DFS(now.x, now.y, step + 1))
            return true;
        vis[now.x][now.y] = 0;
    }
    return false;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    vis[y][x] = 1;
    DFS(y, x, 1);
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            printf("%d ", vis[i][j]);
        printf("\n");
    }
    return 0;
}