#include <iostream>
#include <algorithm>

using namespace std;

int T;

int N, M;
int arr[1000006];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			scanf("%d", arr + n);
		}
		sort(arr, arr + N);

		scanf("%d", &M);
		for (int m = 0; m < M; m++) {
			int number;
			scanf("%d", &number);

			int index = lower_bound(arr, arr + N, number) - arr;

			if (index >= N) printf("%d\n", 0);
			else printf("%d\n", arr[index] == number);
		}
	}

	return 0;
}
