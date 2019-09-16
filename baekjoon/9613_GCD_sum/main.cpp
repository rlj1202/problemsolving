#include <cstdio>

int nums[102];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);
		for (int n = 0; n < N; n++)
			scanf("%d", nums + n);

		long long result = 0;

		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				result += gcd(nums[i], nums[j]);

		printf("%lld\n", result);
	}

	return 0;
}
