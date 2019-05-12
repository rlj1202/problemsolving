#include <stdio.h>

int K;

int main() {
	scanf("%d", &K);

	int result = 0;

	for (int day = 1; day <= K; day++) {
		result += day;
	}

	printf("%d\n", result);

	return 0;
}
