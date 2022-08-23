#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    cout << '<';

    int i = N - 1;
    int remains = N;
    while (remains--) {
        int cur = K;
        while (cur) {
            i = (i + 1) % N;
            if (!check[i]) cur--;
        }

        check[i] = true;

        cout << (i + 1);
        if (remains) cout << ", ";
    }

    cout << '>';
    cout << '\n';

    return 0;
}
