#include <cstdio>

int arr[200005];

int main() {
	int N;
	scanf("%d", &N);

	if (N % 2 == 0) {
		printf("NO\n");
	} else {
		for (int n = 0; n < N; n++) {
			if (n % 2 == 0) {
				arr[n] = n * 2 + 1;
				arr[n + N] = n * 2 + 2;
			} else {
				arr[n + N] = n * 2 + 1;
				arr[n] = n * 2 + 2;
			}
		}

		printf("YES\n");
		for (int n = 0; n < N*2; n++) printf("%d ", arr[n]);
		printf("\n");
	}

	return 0;
}
