#include <bits/stdc++.h>

using namespace std;

int sum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;

    long long result = 0;

    // 1 2 3 4 5 6 7 8 9 10
    // 1   3   5   7   9
    // 1     4     7     10
    // 1       5       9
    // 1         6          
    // 1           7
    // 1             8
    // 1               9
    // 1                 10
    // 1

    for (int n = 1; n <= N;) {
        int q = (N + n - 1) / n;
        int r = N - (q - 1) * n - 1;

        if (q == 1) {
            result += 1;
            break;
        }

        int distribution = r / (q - 1);

        result += q * (distribution + 1);

        if (distribution) n += distribution + 1;
        else n++;
    }

    cout << result << "\n";

    return 0;
}
