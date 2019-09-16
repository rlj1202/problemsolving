#include <cstdio>

long long sum[1000006];
long long count[1003];

int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	for (int n = 1; n <= N; n++) {
		long long num;
		scanf("%lld", &num);
		sum[n] = num + sum[n - 1];
	}

	long long result = 0;

	count[0] = 1;
	for (int n = 1; n <= N; n++) result += count[sum[n] % M]++;

	printf("%lld\n", result);

	return 0;
}
