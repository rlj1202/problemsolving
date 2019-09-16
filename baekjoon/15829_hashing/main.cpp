#include <cstdio>

const long long R = 31;
const long long M = 1234567891;

char str[52];

int main() {
	int L;
	scanf("%d %s", &L, str);

	long long hash = 0;

	for (int l = 0; l < L; l++) {
		int cur = str[L - l - 1] - 'a' + 1;

		hash *= R;
		hash += cur;
		hash %= M;
	}

	printf("%lld\n", hash);

	return 0;
}
