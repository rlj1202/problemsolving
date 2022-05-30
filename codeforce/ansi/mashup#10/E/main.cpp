#include <cstdio>

using namespace std;

char map[1003][1003];

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    for (int n = 1; n <= N; n++) {
        scanf("%s", map[n] + 1);
    }

    int icons = 0;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            map[n][m] = map[n][m] == '*';

            icons += map[n][m];
        }
    }

    int icons_inplace = 0;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            if (map[n][m] && n + (m-1) * N <= icons) {
                icons_inplace++;
            }
        }
    }

    while (Q--) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (map[x][y]) {
            if (x + (y-1) * N <= icons) {
                icons_inplace--;
            }

            int r = (icons - 1) % N + 1;
            int c = (icons - 1) / N + 1;
            if (map[r][c] && (x != r || y != c)) {
                icons_inplace--;
            }

            icons--;
        } else {
            icons++;

            if (x + (y-1) * N <= icons) {
                icons_inplace++;
            }

            int r = (icons - 1) % N + 1;
            int c = (icons - 1) / N + 1;
            if (map[r][c] && (x != r || y != c)) {
                icons_inplace++;
            }
        }

        map[x][y] = !map[x][y];

        printf("%d\n", icons - icons_inplace);
    }

    return 0;
}
