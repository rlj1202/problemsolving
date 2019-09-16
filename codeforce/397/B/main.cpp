#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		long long N, L, R;
		scanf("%lld %lld %lld", &N, &L, &R);

		long long rods = N / L;
		long long remains = N % L;

		bool possible = rods * (R - L) >= remains;

		printf("%s\n", possible ? "Yes" : "No");
	}

	return 0;
}
