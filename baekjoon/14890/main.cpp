#include <algorithm>
#include <cstdio>

using namespace std;

int grid[102][102];

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            scanf("%d", &grid[r][c]);
        }
    }

    int answer = 0;

    for (int r = 0; r < N; r++) {
        int len = 1;
        bool valid = true;

        for (int c = 1; c < N; c++) {
            int prev = grid[r][c - 1];
            int cur = grid[r][c];

            if (prev == cur) {
                len++;
                continue;
            }
            if (cur - prev == 1 && len >= L) {
                len = 1;
                continue;
            }
            if (cur - prev == -1 && N - c >= L) {
                int i = 0;
                while (c + i < N && i < L && cur == grid[r][c + i]) {
                    i++;
                }

                if (i == L) {
                    len = 0;
                    c += L - 1;
                    continue;
                }
            }

            valid = false;
            break;
        }

        answer += valid;
    }

    for (int c = 0; c < N; c++) {
        int len = 1;
        bool valid = true;

        for (int r = 1; r < N; r++) {
            int prev = grid[r - 1][c];
            int cur = grid[r][c];

            if (prev == cur) {
                len++;
                continue;
            }
            if (cur - prev == 1 && len >= L) {
                len = 1;
                continue;
            }
            if (cur - prev == -1 && N - r >= L) {
                int i = 0;
                while (r + i < N && i < L && cur == grid[r + i][c]) {
                    i++;
                }
                if (i == L) {
                    len = 0;
                    r += L - 1;
                    continue;
                }
            }

            valid = false;
            break;
        }

        answer += valid;
    }

    printf("%d\n", answer);

    return 0;
}
