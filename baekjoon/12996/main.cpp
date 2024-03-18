#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[52][52][52][52];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int S; // 50
    cin >> S;

    int A, B, C;
    cin >> A >> B >> C;

    dp[0][A][B][C] = 1;

    for (int s = 1; s <= S; s++) {
        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    dp[s][a][b][c] += dp[s - 1][a + 1][b][c];
                    dp[s][a][b][c] %= MOD;
                    dp[s][a][b][c] += dp[s - 1][a][b + 1][c];
                    dp[s][a][b][c] %= MOD;
                    dp[s][a][b][c] += dp[s - 1][a][b][c + 1];
                    dp[s][a][b][c] %= MOD;

                    dp[s][a][b][c] += dp[s - 1][a + 1][b + 1][c];
                    dp[s][a][b][c] %= MOD;
                    dp[s][a][b][c] += dp[s - 1][a + 1][b][c + 1];
                    dp[s][a][b][c] %= MOD;
                    dp[s][a][b][c] += dp[s - 1][a][b + 1][c + 1];
                    dp[s][a][b][c] %= MOD;

                    dp[s][a][b][c] += dp[s - 1][a + 1][b + 1][c + 1];
                    dp[s][a][b][c] %= MOD;
                }
            }
        }
    }

    cout << dp[S][0][0][0] << '\n';

    return 0;
}
