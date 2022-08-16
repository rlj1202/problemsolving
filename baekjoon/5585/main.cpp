#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int M;
    cin >> M;

    M = 1000 - M;

    int result = 0;

    while (M) {
        if (M >= 500) { M -= 500; result++; }
        else if (M >= 100) { M -= 100; result++; }
        else if (M >= 50) { M -= 50; result++; }
        else if (M >= 10) { M -= 10; result++; }
        else if (M >= 5) { M -= 5; result++; }
        else if (M >= 1) { M -= 1; result++; }
    }

    cout << result << '\n';

    return 0;
}
