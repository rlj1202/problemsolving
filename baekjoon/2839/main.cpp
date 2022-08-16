#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int result = 0x3f3f3f3f;

    for (int i = 0; i <= (N/5); i++) {
        int remains = N - i * 5;
        if (remains % 3 != 0) continue;

        int cur = i + remains / 3;
        result = min(result, cur);
    }

    cout << (result != 0x3f3f3f3f ? result : -1) << endl;

    return 0;
}
