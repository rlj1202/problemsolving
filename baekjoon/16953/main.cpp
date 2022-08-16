#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int result = 0;
    bool valid = true;

    while (B != A && B) {
        int digit = B % 10;
        if (digit == 1) {
            B /= 10;
        } else if (B % 2 == 0) {
            B /= 2;
        } else {
            valid = false;
            break;
        }

        result++;
    }
    if (A != B) valid = false;

    if (valid) cout << result + 1 << '\n';
    else cout << -1 << '\n';

    return 0;
}
