#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int revs = 1;

    int j = 0;
    for (int i = 0; i < (int) B.length();) {
        if (B[i] == A[j]) {
            i++;
            if (i == (int) B.length()) {
                break;
            }
        }

        j++;
        if (j == (int) A.length()) {
            j = 0;
            revs++;
        }
    }

    cout << revs << '\n';

    return 0;
}
