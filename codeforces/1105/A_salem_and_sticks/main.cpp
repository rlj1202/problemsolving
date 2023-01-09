#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1003];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}
	sort(arr, arr + N);

	int result_t = 1;
	int mincost = 0x3f3f3f3f;

	for (int t = 1; t <= arr[N - 1]; t++) {
		int cost = 0;

		for (int n = 0; n < N; n++) {
			int cur = arr[n];

			if (cur > t) {
				cost += cur - t - 1;
			} else if (cur < t) {
				cost += t - cur - 1;
			}
		}

		if (mincost > cost) {
			mincost = cost;
			result_t = t;
		}
	}

	printf("%d %d\n", result_t, mincost);

	return 0;
}
