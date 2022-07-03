#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<long double, int> element;

vector<element> v;
vector<long double> weights;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int n = 0; n < N; n++) {
        struct tm time = {0};
        int hard;

        cin >> get_time(&time, "%Y/%m/%d %H:%M:%S");
        cin >> hard;

        v.push_back({ (long double) mktime(&time), hard });
    }

    sort(v.begin(), v.end());

    auto [last_time, temp] = v.back();

    long double weight_sum = 0;
    for (int i = 1; i <= N; i++) {
        auto cur = v[i - 1];
        auto [time, hard] = cur;

        long double weight = max(
            pow(0.5L, (last_time - time) /60/60/24/365),
            pow(0.9L, N - i));
        weights.push_back(weight);

        weight_sum += weight;
    }

    long double x = 0;
    for (int i = 0; i < N; i++) {
        auto [time, hard] = v[i];
        x += weights[i] * hard;
    }
    x /= weight_sum;

    ll result = ceil((ll) (x * 10) / 10.0L);

    cout << result << '\n';

    return 0;
}
