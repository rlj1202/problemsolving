#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int last_id = 1;
int go[20 * 15 + 2][3];
int fail[20 * 15 + 2];
int output[20 * 15 + 2];

void insert(const char *str) {
    int cur_id = 1; // 1 = root

    while (true) {
        if (*str == '\0') {
            output[cur_id]++;
            break;
        }

        int idx = *str - 'A';
        if (!go[cur_id][idx]) {
            go[cur_id][idx] = ++last_id;
        }
        cur_id = go[cur_id][idx];

        str++;
    }
}

int dp[1003][20 * 15 + 2];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;
        insert(str.c_str());
    }

    queue<int> q;
    q.push(1);
    fail[1] = 1;

    while (!q.empty()) {
        int cur_id = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next_id = go[cur_id][i];
            if (!next_id) continue;

            if (cur_id == 1) {
                fail[next_id] = 1;
                q.push(next_id);
                continue;
            }

            int dest_id = fail[cur_id];
            while (dest_id != 1 && !go[dest_id][i]) {
                dest_id = fail[dest_id];
            }

            if (go[dest_id][i]) {
                dest_id = go[dest_id][i];
            }

            fail[next_id] = dest_id;
            if (output[dest_id]) {
                output[next_id] += output[dest_id];
            }

            q.push(next_id);
        }
    }

    memset(dp, -1, sizeof(dp));

    dp[0][1] = 0;

    for (int k = 0; k <= K; k++) {
        for (int id = 1; id <= last_id; id++) {
            if (dp[k][id] == -1) continue;

            for (int i = 0; i < 3; i++) {
                int cur = id;

                while (cur != 1 && !go[cur][i]) {
                    cur = fail[cur];
                }
                if (go[cur][i]) cur = go[cur][i];

                dp[k + 1][cur] = max(dp[k + 1][cur], dp[k][id] + output[cur]);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= last_id; i++) {
        answer = max(answer, dp[K][i]);
    }

    cout << answer << '\n';

    return 0;
}
