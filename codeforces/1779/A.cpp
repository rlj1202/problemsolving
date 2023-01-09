#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        // ...R...L... can illuminate all the trophies.
        // ...LLLRRR... cannot.

        bool illuminated = false;

        bool rFound = false;
        for (int i = 0; S[i]; i++) {
            if (!rFound && S[i] == 'R') {
                rFound = true;
            } else if (rFound && S[i] == 'L') {
                illuminated = true;
                break;
            }
        }

        if (illuminated) {
            cout << 0 << '\n';
        } else {
            bool lrFound = false;
            int pos = 0;

            for (int i = 1; S[i]; i++) {
                if (S[i - 1] == 'L' && S[i] == 'R') {
                    lrFound = true;
                    pos = i;
                    break;
                }
            }

            if (lrFound) {
                cout << pos << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
