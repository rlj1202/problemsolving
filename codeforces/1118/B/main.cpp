#include <iostream>

int N;
int candies[200005];
int sum[200005];
long long total;

int main() {
	scanf("%d", &N);

	scanf("%d", candies + 1);
	total += candies[1];
	sum[1] = candies[1];
	for (int n = 2; n <= N; n++) {
		scanf("%d", candies + n);
		total += candies[n];
		sum[n] += candies[n] + sum[n - 2];
	}

	int result = 0;
	
	for (int n = 1; n <= N; n++) {
		int a = sum[n - 1];
		int b = sum[n + ((N - n) / 2) * 2] - sum[n];

		if (a + b == total - a - b - candies[n]) result++;
	}

	printf("%d\n", result);

	return 0;
}
