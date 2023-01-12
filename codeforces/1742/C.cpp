#include <bits/stdc++.h>

using namespace std;

char grid[10][10];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        for (int r = 0; r < 8; r++) {
            cin >> grid[r];
        }

        bool isRed = false;

        // row-wise, red
        for (int r = 0; r < 8; r++) {
            bool stripe = true;

            for (int c = 1; c < 8; c++) {
                if (grid[r][c - 1] != grid[r][c]) {
                    stripe = false;
                    break;
                }
            }

            if (!stripe) continue;

            if (grid[r][0] == 'R') {
                isRed = true;
            }
        }

        // column-wise, blue
        for (int c = 0; c < 8; c++) {
            bool stripe = true;

            for (int r = 1; r < 8; r++) {
                if (grid[r - 1][c] != grid[r][c]) {
                    stripe = false;
                    break;
                }
            }

            if (!stripe) continue;

            if (grid[0][c] == 'B') {
                isRed = false;
            }
        }

        cout << (isRed ? 'R' : 'B') << '\n';
    }

    return 0;
}
