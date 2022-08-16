#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll S;
    cin >> S;

    int result = 0;
    ll cur = 0;
    for (int i = 1; cur + i <= S; i++) {
        cur += i;
        result++;
    }

    cout << result << '\n';

    return 0;
}
