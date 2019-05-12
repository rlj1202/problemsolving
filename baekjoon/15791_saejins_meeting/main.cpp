#include <iostream>

int N, M;

int arr1[1000006];
int arr2[1000006];

int main() {
	scanf("%d %d", &N, &M);

	if (N / 2 < M) M = N - M;

	int *cur = arr1;
	int *nxt= arr2;

	cur[0] = 1;
	nxt[0] = 1;
	
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= n; m++) {
			nxt[m] = cur[m - 1] + cur[m];
			nxt[m] %= 1000000007;
		}
		int *tmp = cur;
		cur = nxt;
		nxt = tmp;
	}

	printf("%d\n", cur[M]);

	return 0;
}
