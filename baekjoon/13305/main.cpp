#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dists[100005];
ll prices[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N - 1; n++) {
        cin >> dists[n];
    }
    for (int n = 0; n < N; n++) {
        cin >> prices[n];
    }

    ll result = 0;
    ll min_price = prices[0];
    for (int n = 0; n < N - 1; n++) {
        min_price = min(min_price, prices[n]);
        result += min_price * dists[n];
    }

    cout << result << '\n';

    return 0;
}
