#include <cstdio>
#include <cstring>

char maps[10][10];
bool vis1[10], vis2[20], vis3[20];
int ans = 0;

void DFS(int x) {
    if (x > 8) {
        ans++;
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (maps[x][i] == '*' || vis1[i] || vis2[x + i] || vis3[x - i + 8])
            continue;
        vis1[i] = vis2[x + i] = vis3[x - i + 8] = true;
        DFS(x + 1);
        vis1[i] = vis2[x + i] = vis3[x - i + 8] = false;
    }
    return;
}

int main() {
    for (int i = 1; i <= 8; i++)
        scanf("%s", maps[i] + 1);

    DFS(1);

    printf("%d", ans);
    return 0;
}