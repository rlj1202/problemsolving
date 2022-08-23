#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int cur = 666;

    while (--N) {
        cur++;
        while (true) {
            int temp = cur;
            int sixes = 0;

            int len = 0;
            while (temp) {
                if (temp % 10 == 6) {
                    len++;
                    sixes = max(sixes, len);
                } else {
                    len = 0;
                }
                temp /= 10;
            }

            if (sixes >= 3) break;

            cur++;
        }
    }

    cout << cur << '\n';

    return 0;
}
