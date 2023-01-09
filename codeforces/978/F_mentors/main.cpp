#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[200005];
int sorted[200005];

int result[200005];

int main() {
	// read input
	scanf("%d %d", &N, &K);

	for (int n = 1; n <= N; n++) {
		scanf("%d", arr + n);
		sorted[n] = arr[n];
	}
	sort(sorted + 1, sorted + 1 + N);

	// handle quarrel
	for (int k = 1; k <= K; k++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (arr[a] == arr[b]) continue;

		if (arr[a] > arr[b]) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		result[b]--;
	}

	// count
	for (int n = 1; n <= N; n++) {
		int index = lower_bound(sorted + 1, sorted + 1 + N, arr[n]) - sorted - 1;
		result[n] += index;
	}

	// print result
	for (int n = 1; n <= N; n++) {
		printf("%d ", result[n]);
	}
	printf("\n");

	return 0;
}
