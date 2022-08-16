#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int L, P, V;
    int T = 0;
    while (cin >> L >> P >> V) {
        if (!L && !P && !V) break;
        T++;

        int result = (V / P) * L + min(V % P, L);

        cout << "Case " << T << ": " << result << '\n';
    }

    cout << '\n';

    return 0;
}
