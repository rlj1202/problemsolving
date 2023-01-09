#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int costs[300005];
long long sum;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", costs + n);
		sum += costs[n];
	}
	sort(costs, costs + N, greater<int>());

	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		int coupon;
		scanf("%d", &coupon);

		long long result = sum - costs[coupon - 1];

		printf("%lld\n", result);
	}

	return 0;
}
