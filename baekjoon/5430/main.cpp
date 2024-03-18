#include <bits/stdc++.h>

using namespace std;

char cmd[100005];

int arr[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> cmd;

        int N;
        cin >> N;

        cin.ignore();
        char temp;
        cin >> temp;
        for (int n = 0; n < N; n++) {
            cin >> arr[n];
            cin >> temp;
        }
        if (N == 0) {
            cin >> temp;
        }

        bool rev = false;
        int l = 0;
        int r = N;

        bool error = false;

        for (int i = 0; cmd[i]; i++) {
            char cur = cmd[i];

            if (cur == 'R') {
                rev = !rev;
            } else if (cur == 'D') {
                if (rev == false) {
                    l++;
                } else {
                    r--;
                }

                if (l > r) {
                    error = true;
                    break;
                }
            }
        }

        if (error) {
            cout << "error\n";
        } else {
            cout << '[';
            if (rev == false) {
                for (int i = l; i < r; i++) {
                    cout << arr[i];
                    if (i < r - 1) cout << ',';
                }
            } else {
                for (int i = r - 1; i >= l; i--) {
                    cout << arr[i];
                    if (i >= l + 1) cout << ',';
                }
            }
            cout << ']';
            cout << '\n';
        }
    }

    return 0;
}
