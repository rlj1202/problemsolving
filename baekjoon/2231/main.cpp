#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int result = 0;

    for (int n = 1; n <= N; n++) {
        int sum = n;

        int cur = n;
        while (cur) {
            sum += cur % 10;
            cur /= 10;
        }

        if (sum == N) {
            result = n;
            break;
        }
    }

    cout << result << '\n';

    return 0;
}
