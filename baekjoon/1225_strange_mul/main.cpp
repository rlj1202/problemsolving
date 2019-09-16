#include <cstdio>

char A[10004];
char B[10004];

int main() {
	scanf("%s %s", A, B);

	long long result = 0;

	for (int i = 0; A[i]; i++)
		for (int j = 0; B[j]; j++)
			result += (A[i] - '0') * (B[j] - '0');

	printf("%lld\n", result);

	return 0;
}
