#include <cstdio>
#include <algorithm>

using namespace std;

int N;

bool cols[100005];
bool rdigs[100005 * 2];
bool ldigs[100005 * 2];

int answers[100005];

bool dfs(int row, int col) {
    int rdig = col - row + N;
    int ldig = col + row;

    if (cols[col]) return false;
    if (rdigs[rdig]) return false;
    if (ldigs[ldig]) return false;

    cols[col] = true;
    rdigs[rdig] = true;
    ldigs[ldig] = true;

    answers[row] = col;

    if (row == N - 1) {
        return true;
    }

    for (int c = 0; c < N; c++) {
        if (c == col) continue;
        if (c == col - 1) continue;
        if (c == col + 1) continue;
        if (dfs(row + 1, c)) {
            return true;
        }
    }

    cols[col] = false;
    rdigs[rdig] = false;
    ldigs[ldig] = false;

    return false;
}

int main() {
    scanf("%d", &N);

    for (int c = 0; c < N; c++) {
        if (dfs(0, c)) {
            break;
        }
    }

    for (int n = 0; n < N; n++) {
        printf("%d\n", answers[n] + 1);
    }

    return 0;
}
