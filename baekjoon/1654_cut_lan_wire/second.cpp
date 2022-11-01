#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int K, N;
    cin >> K >> N;
    vector<ll> arr(K);
    for (ll &value : arr) cin >> value;

	ll l = 0;
	ll r = 1LL << 31;

	while (l < r) {
	    ll mid = (l + r + 1) / 2;

		ll wires = 0;
		for (int k = 0; k < K; k++) wires += arr[k] / mid;

		if (wires >= N) l = mid;
		else r = mid - 1;
	}

    cout << l << '\n';

	return 0;
}
