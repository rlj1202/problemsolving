#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 998244353;

int N;
pair<int, int> arr[200005];

vector<pair<int, int>> segments;

int main() {
	// read input and sort
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);
		arr[n] = {value, n};
	}
	sort(arr, arr + N);

	// make segments
	pair<int, int> last = arr[0];
	for (int n = 0; n <= N; n++) {
		pair<int, int> cur = arr[n];
		if (last.first != cur.first) {
			segments.push_back({last.second, arr[n - 1].second});
			last = cur;
		}
	}
	sort(segments.begin(), segments.end());

	// count the number of combined segments
	int count = 0;
	
	int rightmost = -1;
	for (pair<int, int> seg : segments) {
		if (rightmost < seg.first) count++;
		rightmost = max(rightmost, seg.second);
	}

	// calculate and print result
	long long result = 1;

	int exp = count - 1;
	long long base = 2;
	while (exp > 0) {
		if ((exp & 1) == 1) result *= base;
		result %= MOD;

		exp >>= 1;
		base = (base * base) % MOD;
	}

	printf("%lld\n", result);

	return 0;
}
