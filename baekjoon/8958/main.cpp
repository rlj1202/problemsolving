#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;

        int answer = 0;

        int cur = 0;
        for (int i = 0; S[i]; i++) {
            if (S[i] == 'O') {
                cur++;
            } else {
                cur = 0;
            }

            answer += cur;
        }

        cout << answer << '\n';
    }

    cout << '\n';

    return 0;
}
