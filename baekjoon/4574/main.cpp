#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int grid[11][11];
bool used[11][11];

void print_grid() {
    for (int r = 1; r <= 9; r++) {
        printf("\t");
        for (int c = 1; c <= 9; c++) {
            printf("%d", grid[r][c]);
        }
        printf("\n");
    }
}

bool check_row(int r) {
    bool check[10];
    memset(check, false, sizeof(check));
    for (int c = 1; c <= 9; c++) {
        if (!grid[r][c])
            continue;
        if (check[grid[r][c]])
            return false;
        check[grid[r][c]] = true;
    }
    return true;
}

bool check_col(int c) {
    bool check[10];
    memset(check, false, sizeof(check));
    for (int r = 1; r <= 9; r++) {
        if (!grid[r][c])
            continue;
        if (check[grid[r][c]])
            return false;
        check[grid[r][c]] = true;
    }
    return true;
}

bool check_block(int r, int c) {
    bool check[10];
    memset(check, false, sizeof(check));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!grid[r + i][c + j])
                continue;
            if (check[grid[r + i][c + j]])
                return false;
            check[grid[r + i][c + j]] = true;
        }
    }
    return true;
}

bool check_valid() {
    for (int i = 1; i <= 9; i++) {
        if (!check_row(i) || !check_col(i))
            return false;
    }
    for (int i = 1; i <= 9; i += 3) {
        for (int j = 1; j <= 9; j += 3) {
            if (!check_block(i, j))
                return false;
        }
    }

    return true;
}

bool dfs(int remains) {
    if (!check_valid())
        return false;

    if (remains == 6) {
        print_grid();
        printf("\n");
    }

    if (!remains) {
        return check_valid();
    }

    for (int r = 1; r <= 9; r++) {
        for (int c = 1; c <= 9; c++) {
            if (grid[r][c])
                continue;
            if ((c + 1 <= 9 && grid[r][c + 1]) &&
                (r + 1 <= 9 && grid[r + 1][c])) {
                continue;
            }

            for (int u = 1; u <= 9; u++) {
                for (int v = 1; v <= 9; v++) {
                    if (u == v)
                        continue;
                    if (used[u][v])
                        continue;

                    used[u][v] = true;
                    used[v][u] = true;

                    grid[r][c] = u;

                    if (!grid[r][c + 1]) {
                        grid[r][c + 1] = v;
                        if (dfs(remains - 1)) {
                            return true;
                        }
                        grid[r][c + 1] = 0;
                    }

                    if (!grid[r + 1][c]) {
                        grid[r + 1][c] = v;
                        if (dfs(remains - 1)) {
                            return true;
                        }
                        grid[r + 1][c] = 0;
                    }

                    grid[r][c] = 0;

                    used[u][v] = false;
                    used[v][u] = false;
                }
            }
        }
    }

    return false;
}

int main() {
    int T = 0;
    while (true) {
        T++;
        int N;
        scanf("%d", &N);

        if (!N)
            break;

        memset(grid, 0, sizeof(grid));
        memset(used, false, sizeof(used));

        for (int n = 0; n < N; n++) {
            int U, V;
            char ur, vr;
            int uc, vc;
            scanf("%d %c%d", &U, &ur, &uc);
            scanf("%d %c%d", &V, &vr, &vc);
            ur -= 'A' - 1;
            vr -= 'A' - 1;

            grid[ur][uc] = U;
            grid[vr][vc] = V;

            used[U][V] = true;
            used[V][U] = true;
        }

        for (int i = 1; i <= 9; i++) {
            char r;
            int c;
            scanf(" %c%d", &r, &c);

            r -= 'A' - 1;

            grid[r][c] = i;
        }

        dfs(9 * 8 / 2 - N);

        printf("Puzzle %d\n", T);
        print_grid();
    }

    return 0;
}