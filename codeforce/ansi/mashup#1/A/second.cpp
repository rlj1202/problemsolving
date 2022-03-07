#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int grid[302][302];
int target[302];
int col[302];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        memset(grid, 0, sizeof(grid));
        memset(target, 0, sizeof(target));
        memset(col, 0, sizeof(col));

        for (int i = 0; i < K; i++) target[i % N]++;

        for (int r = 0; r < N; r++) {
            for (int i = 0; i < target[r]; i++) {
                int minCol = 0;
                int minColValue = 0x3f3f3f3f;

                for (int c = 0; c < N; c++) {
                    if (minColValue > col[c]) {
                        minColValue = col[c];
                        minCol = c;
                    }
                }

                col[minCol]++;
                grid[r][minCol] = 1;
            }
        }

        int minValue = 0x3f3f3f3f;
        int maxValue = 0;

        for (int i = 0; i < N; i++) {
            minValue = min(minValue, target[i]);
            maxValue = max(maxValue, target[i]);
        }

        int result = pow(minValue - maxValue, 2) * 2;

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
