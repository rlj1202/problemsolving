#include <bits/stdc++.h>

using namespace std;

bool possible[52][52][52][2][3];
tuple<int, int, int, int, int> back[52][52][52][2][3];
int arr[52][52][52][2][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string S;
    cin >> S;

    int A = 0;
    int B = 0;
    int C = 0;

    for (int i = 0; S[i]; i++) {
        char c = S[i];
        if (c == 'A') A++;
        if (c == 'B') B++;
        if (c == 'C') C++;
    }

    // AAAAAAAAA
    // B.B.B.B.B
    // C..C..C..

    possible[A][B][C][0][0] = true;

    memset(arr, -1, sizeof(arr));

    for (int s = 0; s < S.length(); s++) {
        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    for (int br = 0; br < 2; br++) {
                        for (int cr = 0; cr < 3; cr++) {
                            if (possible[a][b][c][br][cr] == false) continue;

                            if (a - 1 >= 0) {
                                possible[a - 1][b][c][max(br - 1, 0)][max(cr - 1, 0)] = true;
                                back[a - 1][b][c][max(br - 1, 0)][max(cr - 1, 0)]
                                    = make_tuple(a, b, c, br, cr);
                                arr[a - 1][b][c][max(br - 1, 0)][max(cr - 1, 0)] = 0;
                            }
                            
                            if (b - 1 >= 0 && br == 0) {
                                possible[a][b - 1][c][1][max(cr - 1, 0)] = true;
                                back[a][b - 1][c][1][max(cr - 1, 0)]
                                    = make_tuple(a, b, c, br, cr);
                                arr[a][b - 1][c][1][max(cr - 1, 0)] = 1;
                            }

                            if (c - 1 >= 0 && cr == 0) {
                                possible[a][b][c - 1][max(br - 1, 0)][2] = true;
                                back[a][b][c - 1][max(br - 1, 0)][2]
                                    = make_tuple(a, b, c, br, cr);
                                arr[a][b][c - 1][max(br - 1, 0)][2] = 2;
                            }
                        }
                    }
                }
            }
        }
    }

    bool valid = false;

    for (int br = 0; br < 2; br++) {
        for (int cr = 0; cr < 3; cr++) {
            bool cur = possible[0][0][0][br][cr];
            valid |= cur;

            if (!cur) continue;

            auto cur = make_tuple(0, 0, 0, br, cr);

            // while (arr[][][][][] != -1) {

            // }
        }
    }

    if (!valid) {
        cout << "-1\n";
    }

    return 0;
}
