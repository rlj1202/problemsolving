#include <bits/stdc++.h>

using namespace std;

char S[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M >> S;

    int answer = 0;

    int cnt = 1;
    for (int i = 1; S[i]; i++) {
        if (S[i] == S[i - 1]) {
            cnt = 1;
        } else {
            cnt++;
        }

        if (S[i] == 'I' && cnt >= N * 2 + 1) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
