#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll l = 2;
    ll r = 0x3f3f3f3f3f3f3f3f;

    while (true) {
        cout << "? 1 " << l << endl;

        ll resp;
        cin >> resp;

        if (resp == -1) {
            r = l;
            l /= 2;
            break;
        }

        l = max(l, resp) * 2;
    }

    while (l < r) {
        ll mid = (l + r + 1) / 2;

        cout << "? 1 " << mid << endl;

        ll resp;
        cin >> resp;

        if (resp == 0) {
            return 0;
        }

        if (resp == -1) {
            r = mid - 1;
        } else {
            l = max(mid, resp);

            // i) resp <= N / 2
            // ii) resp > N / 2
        }
    }

    cout << "! " << l << endl;

    return 0;
}
