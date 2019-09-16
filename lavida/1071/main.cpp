#include <cstdio>
#include <algorithm>

using namespace std;

int arr[52];

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		for (int n = 0; n < N; n++)
			scanf("%d", arr + n);

		sort(arr, arr + N);

		int prev = 0;
		for (int n = 0; n < N; n++) {
			if (arr[n] != prev) {
				prev = arr[n];
				printf("%d ", arr[n]);
			}
		}
		printf("\n");
	}

	return 0;
}
