#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int R;
        string S;
        cin >> R >> S;

        for (int i = 0; S[i]; i++) {
            for (int r = 0; r < R; r++) {
                cout << S[i];
            }
        }

        cout << '\n';
    }

    cout << '\n';

    return 0;
}
