#include <cstdio>
#include <cmath>

int main() {
	long long N, M;
	scanf("%lld %lld", &N, &M);
	printf("%lld\n", N > M ? N - M : M - N);
	return 0;
}
