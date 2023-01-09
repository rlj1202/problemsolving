#include <bits/stdc++.h>

using namespace std;

bool notSelf[10004];

int d(int n) {
    int sum = n;

    int cur = n;
    while (cur) {
        sum += cur % 10;
        cur /= 10;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int n = 1; n <= 10000; n++) {
        int next = d(n);

        if (next > 10000) continue;

        notSelf[next] = true;
    }

    for (int n = 1; n <= 10000; n++) {
        if (notSelf[n]) continue;

        cout << n << '\n';
    }

    return 0;
}
