#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int b, p, q, r;
        cin >> b >> p >> q >> r;

        int mul = p * q * r;
        int sum = p + q + r;
        v.push_back({ mul, sum, b });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++) {
        auto [mul, sum, back] = v[i];
        cout << back << ' ';
    }
    cout << '\n';

    return 0;
}
