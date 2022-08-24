#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int A, B, V;
    cin >> A >> B >> V;

    int delta = A - B;
    int answer = (V - A + delta - 1) / delta;
    answer += (A <= V);

    cout << answer << '\n';

    return 0;
}
