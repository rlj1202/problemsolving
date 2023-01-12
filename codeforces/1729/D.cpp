#include <bits/stdc++.h>

using namespace std;

int budget[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int n = 1; n <= N; n++) {
            int value;
            cin >> value;
            budget[n] = -value;
        }
        for (int n = 1; n <= N; n++) {
            int value;
            cin >> value;
            budget[n] += value;
        }

        sort(budget + 1, budget + N + 1);

        vector<int> neg;
        vector<int> pos;

        for (int n = 1; n <= N; n++) {
            if (budget[n] < 0) {
                neg.push_back(budget[n]);
            } else {
                pos.push_back(budget[n]);
            }
        }

        int answer = 0;

        for (int n : neg) {
            if (pos.empty()) break;

            if (n + pos.back() >= 0) {
                pos.pop_back();
                answer++;
            }
        }

        answer += pos.size() / 2;

        cout << answer << '\n';
    }

    return 0;
}
