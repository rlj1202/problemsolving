#include <cstdio>
#include <algorithm>

using namespace std;

int grid[1503][1503];
int row_top[1503];

int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            scanf("%d", &grid[c][N - 1 - r]);

    int result = 0;
    for (int n = 0; n < N; n++) {
        int top_row = 0;
        for (int r = 1; r < N; r++) {
            if (grid[top_row][row_top[top_row]] < grid[r][row_top[r]])
                top_row = r;
        }

        result = grid[top_row][row_top[top_row]];

        row_top[top_row]++;
    }

    printf("%d\n", result);

    return 0;
}