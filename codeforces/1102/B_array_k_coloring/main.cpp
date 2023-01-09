#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
pair<int, int> arr[5003];
int colors[5003];

int main() {
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);
		arr[n] = make_pair(value, n);
	}
	sort(arr, arr + N);

	bool possible = true;

	int maxlen = 0;

	int color = 0;

	for (int n = 0; n < N;) {
		int value = arr[n].first;
		
		int m = n;
		while (arr[m].first == value) m++;

		int len = m - n;

		if (K < len) {
			possible = false;
			break;
		}

		maxlen = max(maxlen, len);

		for (int i = 0; i < len; i++) {
			pair<int, int> cur = arr[n + i];
			colors[cur.second] = color + 1;

			color++;
			color %= K;
		}

		n = m;
	}

	if (possible) {
		printf("YES\n");
		for (int n = 0; n < N; n++) {
			printf("%d ", colors[n]);
		}
		printf("\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
