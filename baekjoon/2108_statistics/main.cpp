#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int arr[500005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	ll sum = 0;
	int min_value = 0x3f3f3f3f;
	int max_value = -0x3f3f3f3f;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		sum += arr[n];
		min_value = min(min_value, arr[n]);
		max_value = max(max_value, arr[n]);
	}

	sort(arr, arr + N);

	int mid = arr[N / 2];

	vector<int> frequencies;
	int most_frequent = 0;

	int cnt = 0;
	int prev = arr[0];
	for (int n = 0; n < N; n++) {
		int cur = arr[n];

		if (cur == prev) {
			cnt++;
		} else {
			if (most_frequent < cnt) {
				most_frequent = cnt;
				frequencies.clear();
			}
			if (most_frequent == cnt) {
				frequencies.push_back(prev);
			}
			cnt = 1;
		}

		prev = cur;
	}
	if (most_frequent < cnt) {
		most_frequent = cnt;
		frequencies.clear();
	}
	if (most_frequent == cnt) {
		frequencies.push_back(prev);
	}

	sort(frequencies.begin(), frequencies.end());

    cout << (ll) round(sum / (double) N) << '\n';
	cout << mid << '\n';
	cout << frequencies[min(1, (int) frequencies.size() - 1)] << '\n';
	cout << (max_value - min_value) << '\n';

    return 0;
}
