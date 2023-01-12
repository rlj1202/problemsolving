#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; // ~ 500
    cin >> T;

    while (T--) {
        string str; // ~ 2e5
        cin >> str;

        // b a aaaaa <- possible
        // ... a ... <- possible

        // b b bbbbba <- possible
        // ... b ... <- possible...?

        bool isA = false;
        int aPos;

        for (int i = 1; i < (int) str.length() - 1; i++) {
            if (str[i] == 'a') {
                isA = true;
                aPos = i;
                break;
            }
        }

        string A, B, C;

        if (isA) {
            A = str.substr(0, aPos);
            B = str.substr(aPos, 1);
            C = str.substr(aPos + 1);
        } else {
            A = str.substr(0, 1);
            B = str.substr(1, str.length() - 2);
            C = str.substr(str.length() - 1);
        }

        // if (!((B <= A && B <= C) || (B >= A && B >= C))) {
        //     cout << "wtf\n";
        // }

        cout << A << ' ' << B << ' ' << C << '\n';
    }

    return 0;
}
