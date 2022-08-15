#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 9;

ll pi[102];
ll dp[102][102][102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    string str;
    cin >> N;
    cin >> str;

    {
        int j = 0;
        for (int i = 1; str[i]; i++) {
            while (j && str[i] != str[j]) j = pi[j - 1];
            if (str[i] == str[j]) pi[i] = ++j;
        }
    }

    dp[0][0][0] = 1;

    for (int n = 0; n <= N - 1; n++) {
        for (int k = 0; k <= N; k++) {
            for (int l = 0; l < str.length(); l++) {
                for (int i = 0; i < 2; i++) {
                    char c = "UD"[i];
                    int delta = c == 'U' ? 1 : -1;

                    if (k + delta < 0) continue;

                    int cur = l;
                    while (cur && str[cur] != c) cur = pi[cur - 1];
                    if (str[cur] == c) cur++;

                    dp[n + 1][cur][k + delta] += dp[n][l][k];
                    dp[n + 1][cur][k + delta] %= MOD;
                }
            }

            dp[n + 1][str.length()][k + 1] += dp[n][str.length()][k];
            dp[n + 1][str.length()][k + 1] %= MOD;

            if (k - 1 >= 0) dp[n + 1][str.length()][k - 1] += dp[n][str.length()][k];
            if (k - 1 >= 0) dp[n + 1][str.length()][k - 1] %= MOD;
        }
    }

    cout << dp[N][str.length()][0] << '\n';

    return 0;
}
