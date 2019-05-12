#include <iostream>

int N, K;

int main() {
	scanf("%d %d", &N, &K);

	int possibleMax = 0;

	for (int k = 1; k <= K; k++) {
		int multitab;
		scanf("%d", &multitab);

		possibleMax += (multitab + 1) / 2;
	}

	if (N <= possibleMax) printf("YES\n");
	else printf("NO\n");

	return 0;
}
