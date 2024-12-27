#include <algorithm>
#include <cstdio>

using namespace std;

int N;

char grid[55][55];

int find_max() {
    int answer = 0;

    for (int r = 0; r < N; r++) {
        int len = 1;

        for (int c = 1; c < N; c++) {
            if (grid[r][c - 1] == grid[r][c]) {
                len++;
            } else {
                len = 1;
            }

            answer = max(answer, len);
        }
    }

    for (int c = 0; c < N; c++) {
        int len = 1;

        for (int r = 1; r < N; r++) {
            if (grid[r - 1][c] == grid[r][c]) {
                len++;
            } else {
                len = 1;
            }

            answer = max(answer, len);
        }
    }

    return answer;
}

int main() {
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%s", grid[n]);
    }

    int answer = 0;

    for (int r = 1; r < N; r++) {
        for (int c = 0; c < N; c++) {
            swap(grid[r - 1][c], grid[r][c]);
            answer = max(answer, find_max());
            swap(grid[r - 1][c], grid[r][c]);
        }
    }

    for (int c = 1; c < N; c++) {
        for (int r = 0; r < N; r++) {
            swap(grid[r][c - 1], grid[r][c]);
            answer = max(answer, find_max());
            swap(grid[r][c - 1], grid[r][c]);
        }
    }

    printf("%d\n", answer);

    return 0;
}