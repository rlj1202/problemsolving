#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        multiset<int> ms;

        int K;
        cin >> K;

        while (K--) {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') {
                ms.insert(n);
            } else if (op == 'D' && !ms.empty()) {
                if (n == 1) {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                } else if (n == -1) {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY\n";
        } else {
            auto iter = ms.end();
            iter--;
            cout << *iter << ' ' << *ms.begin() << '\n';
        }
    }

    return 0;
}
