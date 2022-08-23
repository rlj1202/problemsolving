#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char grid[52][52];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        cin >> grid[r];
    }

    int answer = 0x3f3f3f3f;

    for (int offset_r = 0; offset_r <= N - 8; offset_r++) {
        for (int offset_c = 0; offset_c <= M - 8; offset_c++) {
            int cnt_a = 0;
            int cnt_b = 0;

            for (int r = 0; r < 8; r++) {
                for (int c = 0; c < 8; c++) {
                    char target_a = "WB"[(r + c) % 2];
                    char target_b = "BW"[(r + c) % 2];

                    if (grid[offset_r + r][offset_c + c] != target_a) cnt_a++;
                    if (grid[offset_r + r][offset_c + c] != target_b) cnt_b++;
                }
            }

            answer = min(answer, cnt_a);
            answer = min(answer, cnt_b);
        }
    }

    cout << answer << '\n';

    return 0;
}
