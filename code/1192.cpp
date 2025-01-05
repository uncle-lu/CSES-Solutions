#include <cstdio>

const int N = 1e3 + 10;
int n, m, color;
int x_turn[4] = {0, 0, 1, -1};
int y_turn[4] = {1, -1, 0, 0};
char maps[N][N];
bool vis[N][N];

void DFS(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int xx = x + x_turn[i], yy = y + y_turn[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || maps[xx][yy] == '#' || vis[xx][yy])
            continue;
        DFS(xx, yy);
    }
    return;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("\n");
        scanf("%s", maps[i] + 1);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (maps[i][j] == '.' && !vis[i][j]) {
                color++;
                DFS(i, j);
            }
    printf("%d", color);
    return 0;
}