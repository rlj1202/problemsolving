#include <bits/stdc++.h>

using namespace std;

int size2n(char c) {
    switch (c) {
    case 'S': return 0;
    case 'M': return 1;
    case 'L': return 2;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string a, b;
        cin >> a >> b;

        int l = 0;
        int r = 0;

        while (a[l] == 'X') l++;
        while (b[r] == 'X') r++;

        int u = size2n(a.back());
        int v = size2n(b.back());

        if (u == v) {
            if (l == r) {
                cout << "=\n";
            } else if (l < r) {
                if (u == 0) {
                    cout << ">\n";
                } else {
                    cout << "<\n";
                }
            } else {
                if (u == 0) {
                    cout << "<\n";
                } else {
                    cout << ">\n";
                }
            }
        } else if (u < v) {
            cout << "<\n";
        } else {
            cout << ">\n";
        }
    }

    return 0;
}
