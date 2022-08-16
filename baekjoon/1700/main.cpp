#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int orders[102];

bool plugged[102];
int remains[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int k = 0; k < K; k++) {
        cin >> orders[k];

        remains[orders[k]]++;
    }

    int holes = 0;

    int answer = 0;

    for (int k = 0; k < K; k++) {
        int cur = orders[k];

        if (plugged[cur]) {
            continue;
        } else {
            if (holes < N) {
                holes++;
                plugged[cur] = true;
                remains[cur]--;
            } else {
                int to_unplug = -1;

                if (to_unplug == -1) {
                    int max_dist = 0;

                    for (int i = 0; i < K; i++) {
                        if (!plugged[i]) continue;

                        int dist = 0x3f3f3f3f;

                        for (int j = k + 1; j < K; j++) {
                            if (orders[j] == i) {
                                dist = j - k;
                                break;
                            }
                        }

                        if (max_dist < dist) {
                            max_dist = dist;
                            to_unplug = i;
                        }
                    }
                }

                plugged[to_unplug] = false;
                plugged[cur] = true;
                remains[cur]--;
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
