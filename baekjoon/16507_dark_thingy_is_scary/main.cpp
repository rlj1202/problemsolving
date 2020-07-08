#include <cstdio>

using namespace std;

struct point { int r, c; };

int grid[1003][1003];

int main() {
    int R, C, Q;
    scanf("%d %d %d", &R, &C, &Q);
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            scanf("%d", &grid[r][c]);

            grid[r][c] += grid[r - 1][c];
            grid[r][c] += grid[r][c - 1];
            grid[r][c] -= grid[r - 1][c - 1];
        }
    }

    while (Q--) {
        point a, b;
        scanf("%d %d %d %d", &a.r, &a.c, &b.r, &b.c);

        int result = 0;
        result += grid[b.r][b.c];
        result -= grid[b.r][a.c - 1];
        result -= grid[a.r - 1][b.c];
        result += grid[a.r - 1][a.c - 1];

        result /= b.r - a.r + 1;
        result /= b.c - a.c + 1;

        printf("%d\n", result);
    }

    return 0;
}