#include <cstdio>

int line[20], n;

void print() {
    for (int i = 1; i <= n; i++)
        printf("%d", line[i]);
    printf("\n");
    return;
}

int main() {
    scanf("%d", &n);
    int cnt = 1 << n;
    for (int i = 1; i < cnt; i += 2) {
        print();
        line[n] = line[n] == 0 ? 1 : 0;
        print();
        for (int j = n; j >= 1; j--)
            if (line[j] == 1) {
                line[j - 1] = line[j - 1] == 0 ? 1 : 0;
                break;
            }
    }
    return 0;
}