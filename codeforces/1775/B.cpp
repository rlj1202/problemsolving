#include <bits/stdc++.h>

using namespace std;

int number[100005];
int number_len[100005];
int positions[100005];
int positions_len;

int cnt[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        positions_len = 0;

        for (int n = 0; n < N; n++) {
            int K;
            cin >> K;

            number[n] = positions_len;
            number_len[n] = K;

            for (int k = 0; k < K; k++) {
                int pos;
                cin >> pos;

                positions[positions_len++] = pos;
            }
        }

        for (int i = 0; i < positions_len; i++) {
            cnt[positions[i]] = 0;
        }

        for (int i = 0; i < positions_len; i++) {
            cnt[positions[i]]++;
        }

        bool answer = false;

        for (int n = 0; n < N; n++) {
            bool validNumber = true;

            for (int i = 0; i < number_len[n]; i++) {;
                if (cnt[positions[i + number[n]]] < 2) {
                    validNumber = false;
                    break;
                }
            }

            if (validNumber) {
                answer = true;
                break;
            }
        }

        cout << (answer ? "YES" : "NO") << '\n';
    }

    return 0;
}
