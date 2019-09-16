#include <cstdio>

long long wirelens[10004];

int main() {
	int K, N;
	scanf("%d %d", &K, &N);
	for (int k = 0; k < K; k++) scanf("%lld", wirelens + k);

	long long l = 0;
	long long r = 1LL << 31;
	long long mid = (l + r) / 2;

	while (l < r) {
		long long wires = 0;
		for (int k = 0; k < K; k++) wires += wirelens[k] / mid;

		if (wires >= N) l = mid;
		else r = mid - 1;
		mid = (l + r + 1) / 2;
	}

	printf("%lld\n", mid);

	return 0;
}
