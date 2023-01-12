#include <bits/stdc++.h>

using namespace std;

int s[26];
int t[26];

bool isPossible() {
    int j = 25;

    for (int i = 0; i < 26; i++) {
        if (!s[i]) continue;

        while (!t[j] && j > 0) {
            j--;
        }
        if (!t[j]) break;

        if (i < j) return true;
        if (i > j) return false;

        if (s[i] < t[j]) {
            return false;
        }
        if (s[i] > t[j]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int Q;
        cin >> Q;

        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));

        s[0]++;
        t[0]++;

        for (int q = 0; q < Q; q++) {
            int d, k;
            string x;
            cin >> d >> k >> x;

            if (d == 1) {
                for (int i = 0; x[i]; i++) {
                    s[x[i] - 'a'] += k;
                }
            } else if (d == 2) {
                for (int i = 0; x[i]; i++) {
                    t[x[i] - 'a'] += k;
                }
            }

            bool possible = isPossible();

            cout << (possible ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
