#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M; // 2e5, 2e5

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        vector<vector<int>> grid(N, vector<int>(M));

        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                scanf("%d", &grid[n][m]);
            }
        }

        vector<vector<int>> indices(N, vector<int>(2));

        bool valid = true;

        for (int n = 0; n < N; n++) {
            vector<int> sorted = grid[n];
            sort(sorted.begin(), sorted.end());

            indices[n][0] = -1;
            indices[n][1] = -1;

            int len = 0;

            bool row_valid = true;

            for (int m = 0; m < M; m++) {
                if (sorted[m] != grid[n][m]) {
                    if (len < 2) {
                        indices[n][len++] = m;
                    } else {
                        row_valid = false;
                        break;
                    }
                }
            }

            if (!row_valid) {
                valid = false;
                break;
            }
        }

        int a = -1;
        int b = -1;

        for (int n = 0; n < N; n++) {
            if (indices[n][0] != -1 || indices[n][1] != -1) {
                a = indices[n][0];
                b = indices[n][1];
                break;
            }
        }

        if (a == -1 || b == -1) {
            a = 0;
            b = 0;
        }

        for (int n = 0; n < N; n++) {
            if (indices[n][0] != -1 || indices[n][1] != -1) {
                if (indices[n][0] != a || indices[n][1] != b) {
                    valid = false;
                    break;
                }
            } else {
                if (grid[n][a] != grid[n][b]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            printf("%d %d\n", a + 1, b + 1);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
