#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int grid[302][302];
int row[302];
int col[302];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        memset(grid, 0, sizeof(grid));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for (int k = 0; k < (N * N) - K; k++) {
            int minRow = 0;
            int minRowValue = 0x3f3f3f3f;

            for (int r = 0; r < N; r++) {
                if (minRowValue > row[r]) {
                    minRow = r;
                    minRowValue = row[r];
                }
            }

            int minCol = 0;
            int minColValue = 0x3f3f3f3f;

            for (int c = 0; c < N; c++) {
                if (grid[minRow][c] == 0 && minColValue > col[c]) {
                    minCol = c;
                    minColValue = col[c];
                }
            }

            grid[minRow][minCol] = 1;
            row[minRow]++;
            col[minCol]++;
        }

        for (int r = 0; r < N; r++) {
            row[r] = N - row[r];
            col[r] = N - col[r];

            for (int c = 0; c < N; c++) {
                grid[r][c] = !grid[r][c];
            }
        }

        int minRowValue = 0x3f3f3f3f;
        int maxRowValue = 0;
        int minColValue = 0x3f3f3f3f;
        int maxColValue = 0;
        for (int r = 0; r < N; r++) {
            minRowValue = min(minRowValue, row[r]);
            maxRowValue = max(maxRowValue, row[r]);
        }
        for (int c = 0; c < N; c++) {
            minColValue = min(minColValue, col[c]);
            maxColValue = max(maxColValue, col[c]);
        }

        int result = pow(minRowValue - maxRowValue, 2) + pow(minColValue - maxColValue, 2);

        printf("%d\n", result);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                printf("%d", grid[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}
